//
// Created by Nina Potts on 2/25/20.
//

#ifndef GAME_TESTER_TRANSCRIPT_HPP
#define GAME_TESTER_TRANSCRIPT_HPP

#include <string>
#include "Scenario.hpp"
#include "Spell.hpp"

using namespace std;

class Transcript {
public:
    Scenario *getScenario();
    Spell *getSpell();
};


#endif //GAME_TESTER_TRANSCRIPT_HPP
