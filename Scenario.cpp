//
// Created by Nina Potts on 2/25/20.
//

#include "Scenario.hpp"



Scenario::Scenario(string text, Spell* spell, bool success, signed char rating){
    _text = text;
    _spell = spell;
    _success = success;
    _rating = rating;
}