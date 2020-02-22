#ifndef _SPELL_HPP
#define _SPELL_HPP

#include <string>
#include <utility> 

using namespace std;

class Spell{
public:
    string getName();
    int getLevel();

protected:
    pair<string, string> _startSpell;
    pair<string, string> _curSpell;
    int _level;

private:
    void updateLevel();
}

#endif