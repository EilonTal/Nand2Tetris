//
// Created by Roe on 8/24/2020.
//

#ifndef MY_VM_TRANSLATOR_UTILS_H
#define MY_VM_TRANSLATOR_UTILS_H

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

template <typename Out>
void split(const string &s, char delim, Out result);
vector<string> split(const string &s, char delim);
bool isTokenAnnotation(const string & s);
bool doesTokenContainAnnotation(const string & s);
string getTokenWithoutAnnotation(string s);
#endif //MY_VM_TRANSLATOR_UTILS_H
