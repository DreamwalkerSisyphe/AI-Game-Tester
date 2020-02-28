//
// Created by Nina Potts on 2/25/20.
//

#ifndef GAME_TESTER_SPELL_HPP
#define GAME_TESTER_SPELL_HPP

#include <string>
#include <utility>

using namespace std;

class Spell {
public:
    Spell(pair<string, string> startSpell, pair<string, string> curSpell);
    string getName();
    int getLevel();

protected:
    pair<string, string> _startSpell;
    pair<string, string> _curSpell;
    int _level;

private:
    void updateLevel();
};


#endif //GAME_TESTER_SPELL_HPP
