#ifndef _HELPERS_HPP
#define _HELPERS_HPP

#include <bits/stdc++.h>

using namespace std;

void cinclr();
void clean(string& s);
vector<string> getWords(string filename);
pair<string, string> makeSpell();
bool inDict(string verb, string noun);

#endif
