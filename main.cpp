#include "main.h"

#include <iostream>

int main()
{   
    map<string, int> words;
    std::stringstream buffer = failo_skaitimas("history.txt");
    string word;

    while (buffer) {
        if (!buffer.eof()) {
            buffer >> word;
            std::locale loc("en_US.UTF-8");
            
            
            while (!word.empty()) {
                if (std::isalpha(word.front(), loc) == 0) {
                    word.erase(0, 1);
                }
                else if(std::isalpha(word.back(), loc) == 0) {
                    word.pop_back();
                }
                else {
                    break;
                 }
            }
         
            if (ar_zodis(word) and word != "") {
                if (words.find(word) != words.end()) {
                    words[word] = words[word] + 1;
                }
                else {
                    words.insert({ word,1 });
                }
            }
            
        }
        else break;
    };

    for (auto i : words) {
        if (i.second > 1) {
            cout << i.first << " " << i.second << endl;
        }
        
    }

    //failo_isvedimas(words,"sutvarkyti.txt");


}
