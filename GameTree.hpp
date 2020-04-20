#ifndef _GAMETREE_HPP
#define _GAMETREE_HPP

#include "Trie.hpp"
#include "helpers.hpp"

class GameTree {
public:
    GameTree();
    pair<string, string> getBestSpell(string s, string context, int change);

private:
    int eval(Trie::Node* verb, Trie::Node* noun, string context);
    Trie* verbTrie;
    Trie* nounTrie;
};


#endif //_GAMETREE_HPP
