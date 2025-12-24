#include "main.h"

std::stringstream failo_skaitimas(string failo_vardas) {
    std::stringstream buffer;
    std::ifstream fl(failo_vardas);
    buffer << fl.rdbuf();
    fl.close();
    return buffer;
}

bool ar_zodis(string word) {
    std::locale loc("en_US.UTF-8");
    for (int i = 0; i < word.length(); i++) {
      
            if (std::isalpha(word[i],loc) == 0) {
                return false;
            }
        
    }
    return true;
}

void sutvarkyti(string& word) {
    std::locale loc("LT.UTF-8");
    while (std::isalpha(word.front(), loc) == 0) {
        word.erase(0, 1);
    }
    while (std::isalpha(word.back(), loc) == 0) {
        word.pop_back();
    }
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