#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <locale>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::left;
using std::right;
using std::map;
using std::vector;

std::stringstream read_file(string);
void write_file(map<string,int>,string);
void table(map<string, vector<int>>);