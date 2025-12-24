#include "main.h"

std::stringstream read_file(string file_name) {
    std::stringstream buffer;
    std::ifstream fl(file_name);
    buffer << fl.rdbuf();
    fl.close();
    return buffer;
}


void write_file(map<string,int> words, string file_name) {
    string str;
    for (auto i: words) {
        if (i.second >= 2) {
            str += i.first + " " + std::to_string(i.second) + " \n";
        }
        
    }
    std::ofstream out_f(file_name);
    out_f << str;
    out_f.close();
}