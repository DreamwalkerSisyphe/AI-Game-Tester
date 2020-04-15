#include "Transcript.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string.h>


#include <ostream>
#include <vector>

using namespace std;

Transcript::Transcript() {

}

// Spell *Transcript::getStartSpell(){}

Scenario *Transcript::getScenario() {
    std::string spell;
    std::cout << "Players starting spell: ";

    std::string startVerb;
    std::string startNoun;


    std::cin >> startVerb;
    std::cin >> startNoun;
    startSpell.first = startVerb;
    startSpell.second = startNoun;


    std::string scenarioText;
    std::cout << "Enter the scenario text: ";
    std::getline(std::cin, scenarioText);

    std::string currentVerb;
    std::string currentNoun;
    std::cout << "Enter a new spell: ";
    std::cin >> currentVerb;
    std::cin >> currentNoun;
    currentSpell.first = currentVerb;
    currentSpell.second = currentNoun;
    Spell *mySpell = new Spell(startSpell, currentSpell);

    int i;
    srand(time(NULL));
    std::vector <int> diceRolls;
    //dice rolls
    for(int j = 0 ; j < 6; j ++){

        i   = (rand()%6)+1;
        diceRolls.push_back(i);
    }

    int successfulRolls = 0;
    for(int i = 0; i < diceRolls.size(); i ++){
        if(diceRolls[i] == 6){
            //roll an extra dice
            //std::cout<< "A dice was 6";
            int t;
            srand(time(NULL));
            t   = (rand()%6)+1;
            diceRolls[i] = t;
            i--;
        }else if(diceRolls[i] >= mySpell->getLevel()){
            successfulRolls++;
        }
    }
    bool successfulSpell = false;
    if(successfulRolls >= mySpell->getLevel()){
        successfulSpell = true;
    }

    std::cout << "Dice: " << successfulRolls << "successful dice rolls. ";
    if(successfulSpell){
        std::cout<< "Spell successfully cast. \n";
    }

    signed char successRating;
    std::cout << "Success rating: ";
    std::cin >> successRating;

    Scenario *s = new Scenario(scenarioText, mySpell, successfulSpell, successRating);

    return s;
}
