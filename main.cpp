#include "main.h"

#include <iostream>

int main()
{   
    int choice;
    cout << "Dalis: ";
    std::cin >> choice;

    //map<string, int> words;
    std::stringstream buffer = read_file("history.txt");
    std::locale loc("en_US.UTF-8");

    if (choice == 1) {
        map<string, int> map;
        string word;

        while (buffer) {
            if (!buffer.eof()) {
                buffer >> word;



                while (!word.empty()) {
                    if (std::isalpha(word.front(), loc) == 0) {
                        word.erase(0, 1);
                    }
                    else if (std::isalpha(word.back(), loc) == 0) {
                        word.pop_back();
                    }
                    else {
                        break;
                    }
                }


                if (word != "") {
                    if (map.find(word) != map.end()) {
                        map[word] = map[word] + 1;
                    }
                    else {
                        map.insert({ word,1 });
                    }
                }

            }
            else break;
        };

        for (auto i : map) {
            if (i.second > 1) {
                cout << i.first << " " << i.second << endl;
            }

        }

        //write_file(map, "map.txt");
    }

}
