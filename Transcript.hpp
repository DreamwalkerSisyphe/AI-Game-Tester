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
    Transcript();
    Scenario *getScenario();

private:
    std::vector <Scenario> allScenarios;
};


#endif //GAME_TESTER_TRANSCRIPT_HPP
