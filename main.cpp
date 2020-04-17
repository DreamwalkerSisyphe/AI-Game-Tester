#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include "Transcript.hpp"

using namespace std;


pair<string, string> makeSpell(){

  pair<string, string> spellPair;
  ifstream verbs("verbs.txt");
  ifstream nouns("nouns.txt");

  string verb;
  string noun;
  int verbNum = (rand() % 1042) + 1;
  int nounNum = (rand() % 1435) + 1;

  for(int i = 0; i < verbNum; i++){
      getline(verbs, verb);
  }
  for(int i = 0; i < nounNum; i++){
      getline(nouns, noun);
  }
  if(verb[verb.size()-1] == '\r' || verb[verb.size()-1] == '\n') //Thank linux for making this even necessary
      verb.pop_back();
  if(noun[noun.size()-1] == '\r' || noun[noun.size()-1] == '\n') //Thank linux for making this even necessary
      noun.pop_back();
  spellPair.first = verb;
  spellPair.second = noun;

  verbs.close();
  nouns.close();

  return spellPair;
}


int main(){
    srand(time(NULL));
    pair<string, string> startSpell = makeSpell();
    cout << "Player's starting spell: " << startSpell.first + " " + startSpell.second << endl;

    Transcript* T = new Transcript(startSpell);
    char c;
    do{
        T->getScenario();
        cout << "Continue? (y/n):";
        while(cin.get() == '\n'); //Clear excessive newlines.
        cin.unget();
        cin >> c;
        cout << endl;
    }while(c == 'y');
    cout << "Describe the ending: ";
    string finale;
    while(cin.get() == '\n'); //Clear excessive newlines.
    cin.unget();
    getline(cin, finale);
    T->setEnding(finale);

    cout << "Transcribed session as " << T->transcribe() << endl;

    exit(0);
}



