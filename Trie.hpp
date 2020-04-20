#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>
#include "helpers.hpp"

using namespace std;

class Trie {
public:
    Trie();
    struct Node{
        Node(string _word);
        vector<Node*> getWords(string s, int changes, bool complete);
        vector<Node*> letters;
        string word;
        bool end;
    };
    Node* insert(string word);
    Node* search(string word);
    Node* getRoot();
private:
    Node* root;
};

#endif