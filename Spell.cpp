
#include "Spell.hpp"

Spell::Spell(pair<string, string> startSpell, pair<string, string> curSpell){
    _startSpell = startSpell;
    _curSpell = curSpell;
    updateLevel();
}

string Spell::getName(){return _curSpell.first + " " + _curSpell.second;}

int Spell::getLevel(){return _level;}

void Spell::updateLevel(){
    string start = _startSpell.first + " " + _startSpell.second;
    string cur = getName();
    int charCountStart[26]; int charCountCur[26];
    for(char c : start){
        if(c >= 'a' && c <= 'z')
            charCountStart[c - 'a']++;
    }
    for(char c : cur){
        if(c >= 'a' && c <= 'z')
            charCountCur[c - 'a']++;
    }
    _level = 1;
    for(int i = 0; i < 26; i++){
        _level += abs(charCountStart[i] - charCountCur[i]);
    }
}
