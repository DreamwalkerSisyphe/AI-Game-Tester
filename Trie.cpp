#include "Trie.hpp"

Trie::Trie(){
    root = new Node("");
}

Trie::Node::Node(string _word){
    vector<Node*> _letters(26, nullptr);
    letters = _letters;
    word = _word;
    end = false;
}

vector<Trie::Node*> Trie::Node::getWords(string s, int changes, bool complete){
    vector<Trie::Node*> words;
    string text = s;
    if(s.empty()){ //Leaf node
        if(end)
            words.push_back(this);
        return words;
    }
    if(!complete && end) //If its a word and we don't need to use the whole string
        words.push_back(this);
    for(int i = 0; i < s.size(); i++) { //Anagrams
        Node *newNode = letters[s[i] - 'a'];
        if (newNode != nullptr) {
            string a = s;
            vector<Node *> add = newNode->getWords(a.erase(i, 1), changes, complete);
            words.insert(words.end(), add.begin(), add.end());
        }
    }
    if(changes > 0){
        for(Node* n : letters) // Additions
            if(n){
                vector<Node*> add = n->getWords(s, changes-1, complete);
                words.insert(words.end(), add.begin(), add.end());
            }

        for(int i = 0; i < s.size(); i++){ //Removals
            string r = s;
            vector<Node*> add = this->getWords(r.erase(i, 1), changes-1, complete);
            words.insert(words.end(), add.begin(), add.end());
        }
    }
    return words;
}

Trie::Node* Trie::insert(string word) {
    Node* parent = root;
    for(unsigned int i = 0; i < word.size(); i++){
        if(parent->letters[word[i]-'a'] != nullptr)
            parent = parent->letters[word[i]-'a'];
        else{
            Node* next = new Node(word.substr(0, i+1));
            parent->letters[word[i]-'a'] = next;
            parent = next;
        }
    }
    parent->end = true;
    return parent;
}

Trie::Node* Trie::search(string word) {
    Node* parent = root;
    for(unsigned int i = 0; i < word.size(); i++){
        if(parent->letters[word[i]-'a'] != nullptr)
            parent = parent->letters[word[i]-'a'];
        else{
            parent = nullptr;
            break;
        }
    }
    return parent;
}

Trie::Node* Trie::getRoot() {
    return root;
}