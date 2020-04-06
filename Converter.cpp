#include <iostream>
#include <string>
#include <fstream>
#include "Scenario.hpp"
#include "Transcript.hpp"

void transcribe(fstream f, Transcript* t){
    char g = 29;
    char u = 31;
    

    Scenario* s = t->getScenario();
    f << t->getStartSpell.first() << " " << t->getStartSpell.second() << g;

    while(s != nullptr){
        f << s->_text << u << s->_spell << u;
        char c = 112;
        if(s->_success)
            c |= 8;
        c |= (unsigned char)(s->_rating+2);
        s = t->getScenario();
    }
}
