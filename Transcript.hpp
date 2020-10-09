#ifndef _TRANSCRIPT_HPP
#define _TRANSCRIPT_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "GameTree.hpp"

using namespace std;

class Transcript {
public:
    Transcript(pair<string, string> _startSpell);
    void getScenario();
    void setEnding(string _ending);
    string transcribe();

private:
    pair<string, string> currentSpell;
    vector<Scenario*> allScenarios;
    pair<string, string> startSpell;
    string ending;
};

#endif