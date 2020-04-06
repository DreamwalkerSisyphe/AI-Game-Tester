#include "verbs.txt"
#include "nouns.txt"
#include "fstream"
#include "iostream"
#include <fstream>
#include <ctime>

using namespace std;


pair<string, string> makeSpell(){

  pair<string, string> spellPair;

    string verb;
    string noun;
    int random = 0;
    int numOfLines = 0;
    ifstream File("verbs.txt");
    ifstream File("nouns.txt");

    srand(time(0));
    random = rand() % 50;

    while(getline(File, verb))
    {
        ++numOfLines;
        if(numOfLines == random)
        {
            cout << verb;
        }   
    }
    while(getline(File, noun))
    {
        ++numOfLines;
        if(numOfLines == random)
        {
            cout << noun;
        }   
    }

}


int main(){
    string senario;
    cout << "Interpreter input you senario: ";
    cin >> senario;

    cout << "Player your starting senario is: " << senario << endl;
    cout << "Your statrting spell is: " << endl;
}



