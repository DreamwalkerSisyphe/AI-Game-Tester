//
// Created by Nina Potts on 2/25/20.
//

#include "Transcript.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>


#include <ostream>
#include <vector>

using namespace std;



Scenario *Transcript::getScenario() {

    int i;
    srand(time(NULL));
    std::vector <int> diceRolls;
    //dice rolls
    for(int j = 0 ; j < 6; j ++){

        i   = (rand()%6)+1;
        diceRolls.push_back(i);
    }


    std::string spell;
    std::cout << "Players starting spell: ";

    std::cin >> spell;

    Spell currentSpell()


    Scenario *scenario(text, spell, success, rating);
    return nullptr;
}



