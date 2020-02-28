//
// Created by Nina Potts on 2/25/20.
//

#ifndef GAME_TESTER_SCENARIO_HPP
#define GAME_TESTER_SCENARIO_HPP


#include <string>
#include "Spell.hpp"

using namespace std;

class Scenario {
public:
    Scenario(string text, Spell *spell, bool success, signed char rating);
    string _text;
    Spell* _spell;
    bool _success;
    signed char _rating; //Don't need need more than a byte to store values -2 to 2

};


#endif //GAME_TESTER_SCENARIO_HPP
