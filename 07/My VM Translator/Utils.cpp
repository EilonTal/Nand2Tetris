//
// Created by Roe on 8/24/2020.
//

#include "Utils.h"



template <typename Out>
void split(const string &s, char delim, Out result)
{
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim)) {
        *result++ = item;
    }
}

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

bool isTokenAnnotation(const string & s)
{
    if (s.find("//") == 0)
        return true;
    return false;
}

bool doesTokenContainAnnotation(const string & s)
{
    if (s.find("//") != string::npos)
        return true;
    return false;
}

string getTokenWithoutAnnotation(string s)
{
    if (doesTokenContainAnnotation(s))
        return s.substr(0, s.find("//"));
    return s;
}