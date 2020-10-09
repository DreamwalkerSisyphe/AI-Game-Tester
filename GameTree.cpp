#include "GameTree.hpp"

#define THRESHOLD 2
#define OPTION_LIMIT 1000

GameTree::GameTree(){
    extern vector<string> verbs;
    extern vector<string> nouns;
    verbTrie = new Trie();
    nounTrie = new Trie();
    for(string v : verbs)
        verbTrie->insert(v);
    for(string n : nouns)
        nounTrie->insert(n);
};

pair<string, string> GameTree::getBestSpell(pair<string, string> orgSpell, pair<string, string> curSpell, string context, int changes = 3){
    double max = numeric_limits<double>::min();
    pair<string, string> b;
    for(Scenario* scene : readScenarios()){
        int diff = compareWords(scene->_text, context);
        double chance = pow(0.5, countDiff(orgSpell.first + " " + orgSpell.second, scene->_spell->getName()));
        int rating = scene->_rating + 3;
        double success = ((double)diff) * chance * rating;
        if(success > max && ((scene->_spell->getVerb() != curSpell.first) || (scene->_spell->getNoun() != curSpell.second))){
            max = success;
            b.first = scene->_spell->getVerb();
            b.second = scene->_spell->getNoun();
        }
    }
    if(max > THRESHOLD)
        return b;
    else {
        string s = orgSpell.first + orgSpell.second;
        vector<pair<Trie::Node *, Trie::Node *>> options;

        //pair<Trie::Node *, Trie::Node *> bestSpell(verbTrie->getRoot(), nounTrie->getRoot());
        //options.push_back(bestSpell);
        vector<Trie::Node *> verbs = verbTrie->getRoot()->getWords(s, changes, false);
        int optionCount = 0;
        for (Trie::Node *v : verbs) {
            if(optionCount > OPTION_LIMIT)
                break;
            vector<Trie::Node *> nouns = nounTrie->getRoot()->getWords(strDiff(s, v->word),changes - countAdditions(s, v->word), true);
            for (Trie::Node *n : nouns) {
                if(optionCount > OPTION_LIMIT)
                    break;
                pair<Trie::Node *, Trie::Node *> newSpell(v, n);
                int oldEval = 0;
                if(options.empty())
                    int oldEval = 0;
                else
                    int oldEval = eval(options[0].first, options[0].second, orgSpell);
                int newEval = eval(newSpell.first, newSpell.second, orgSpell);
                if (oldEval == newEval)
                    options.push_back(newSpell);
                else if (newEval > oldEval) {
                    options.resize(1);
                    options[0] = newSpell;
                }
                optionCount++;
            }
        }
        if(options.empty()){
            cout << "Could not find any usable spell!" << endl;
            exit(404);
        }
        pair<Trie::Node *, Trie::Node *> chosenSpell = options[rand() % options.size()];
        b.first = chosenSpell.first->word;
        b.second = chosenSpell.second->word;
        return b;
    }
}

int GameTree::eval(Trie::Node* verb, Trie::Node* noun, pair<string, string> orgSpell){
    return countDiff(verb->word + noun->word, orgSpell.first + orgSpell.second);
}

vector<Scenario*> GameTree::readScenarios(){
    vector<Scenario*> scenes;
    struct dirent *entry;
    DIR *dir = opendir("./transcripts");
    if(dir == nullptr){
        cout << "Directory doesn't exist. Exiting" << endl;
        exit(909);
    }
    while((entry = readdir(dir)) != nullptr){ //Get transcript files
        string filename = entry->d_name;
        if(filename.size() > 4) {
            ifstream f("transcripts/" + filename);
            if(!f.is_open()){
                cout << "File did not open. Exiting" << endl;
                exit(96);
            }
            char c;
            pair<string, string> start;
            f.get(c);
            while(c != ' '){
                start.first.push_back(c);
                f.get(c);
            }
            f.get(c);
            while(c != 30){
                start.second.push_back(c);
                f.get(c);
            }
            f.get(c);
            while(c != 29){
                string text;
                while(c != 31){
                    text.push_back(c);
                    f.get(c);
                }
                f.get(c);
                pair<string, string> newSpell;
                while(c != ' '){
                    newSpell.first.push_back(c);
                    f.get(c);
                }
                f.get(c);
                while(c != 31){
                    newSpell.second.push_back(c);
                    f.get(c);
                }
                f.get(c);
                Spell* curSpell = new Spell(start, newSpell);
                c ^= 112;
                bool succ = (c & 8 == 8);
                signed char r = (signed char)(c & 7) - 2;
                Scenario* scene = new Scenario(text, curSpell, succ, r);
                scenes.push_back(scene);
                f.get(c);
            }
            f.close();
        }
    }
    return scenes;
}