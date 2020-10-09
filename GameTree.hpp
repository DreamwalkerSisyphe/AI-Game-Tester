#ifndef _GAMETREE_HPP
#define _GAMETREE_HPP

#include <cmath>
#include "Trie.hpp"
#include "Scenario.hpp"
#include <dirent.h>

class GameTree {
public:
    GameTree();
    pair<string, string> getBestSpell(pair<string, string> orgSpell, pair<string, string> curSpell, string context, int change);

private:
    int eval(Trie::Node* verb, Trie::Node* noun, pair<string, string> orgSpell);
    vector<Scenario*> readScenarios();
    Trie* verbTrie;
    Trie* nounTrie;
};


#endif //_GAMETREE_HPP
