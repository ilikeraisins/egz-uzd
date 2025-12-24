#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <locale>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::map;

std::stringstream failo_skaitimas(string);
bool ar_zodis(string);
void sutvarkyti(string&);
void failo_isvedimas(map<string,int>,string);