#include "GameTree.hpp"

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

pair<string, string> GameTree::getBestSpell(string s, string context, int changes){
    vector<pair<Trie::Node*, Trie::Node*>> options;
    pair<Trie::Node*, Trie::Node*> bestSpell(verbTrie->getRoot(), nounTrie->getRoot());
    options.push_back(bestSpell);
    vector<Trie::Node*> verbs = verbTrie->getRoot()->getWords(s, changes, false);
    for(Trie::Node* v : verbs){
        vector<Trie::Node*> nouns = nounTrie->getRoot()->getWords(strDiff(s, v->word), changes-countAdditions(s, v->word), true);
        for(Trie::Node* n : nouns){
            pair<Trie::Node*, Trie::Node*> newSpell(v, n);
            int oldEval = eval(options[0].first, options[0].second, context);
            int newEval = eval(newSpell.first, newSpell.second, context);
            if(oldEval == newEval)
                options.push_back(newSpell);
            else if (newEval > oldEval) {
                options.resize(1);
                options[0] = newSpell;
            }
        }
    }
    pair<Trie::Node*, Trie::Node*> chosenSpell = options[rand() % options.size()];
    pair<string, string> b(chosenSpell.first->word, chosenSpell.second->word);
    return b;
}

int GameTree::eval(Trie::Node* verb, Trie::Node* noun, string context){
    return 1;
}