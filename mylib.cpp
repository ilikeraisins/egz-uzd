#include "main.h"

std::stringstream failo_skaitimas(string failo_vardas) {
    std::stringstream buffer;
    std::ifstream fl(failo_vardas);
    buffer << fl.rdbuf();
    fl.close();
    return buffer;
}


void failo_isvedimas(map<string,int> words, string failo_vardas) {
    string visas;
    for (auto i: words) {
        if (i.second >= 2) {
            visas += i.first + " " + std::to_string(i.second) + " \n";
        }
        
    }
    std::ofstream out_f(failo_vardas);
    out_f << visas;
    out_f.close();
}