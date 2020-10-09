#ifndef _HELPERS_HPP
#define _HELPERS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void cinclr(); //Clears excessive newlines.
void clean(string& s); //Cleans a string of non-alphabetical characters, and makes lowercase
vector<string> getWords(string filename); //Pulls a list of words from a file
pair<string, string> makeSpell(); //Creates a random spell using a verb and noun from dictionary
bool inDict(string verb, string noun); //Checks to see if a given verb and noun exist in dictionary
int countDiff(string pre, string post); //Counts the number of different characters from pre to post
string strDiff(string pre, string post); //Returns a string of characters (in alphabetical order) that are in string pre and not string post
int countAdditions(string pre, string post); //Count how many letters were added from pre to post
int compareWords(string a, string b); //Counts the difference in words in strings a and b
#endif
