#include "main.h"

#include <iostream>

int main()
{   
    int choice;
    cout << "Dalis: ";
    std::cin >> choice;
    cout << endl;

    std::stringstream buffer = read_file("birds.txt");
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

                
                
                if (word != "" and word.find("/") == string::npos and word.find(".") == string::npos) {
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
                cout << left << setw(20) << i.first << " " << i.second << endl;
            }

        }

        //write_file(map, "žodiai.txt");
    }
    else if (choice == 2) {
        map<string, vector<int>> map;

        string word;
        string line;
        int line_nr = 1;

        while (buffer) {
            if (!buffer.eof()) {
                std::getline(buffer, line);

                std::stringstream words(line);
                while (words >> word) {

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

                    if (word != "" and word.find("/") == string::npos and word.find(".") == string::npos) {
                        if (map.find(word) != map.end()) {
                            if (find(map[word].begin(), map[word].end(), line_nr) == map[word].end())
                                map[word].push_back(line_nr);
                        }
                        else {
                            map.insert({ word,{line_nr} });
                        }
                    }
                }
                line_nr++;
            }
            else break;
        };
        table(map);
    }
    else if (choice == 3) {
        vector<string> urls;
        string word;

        while (buffer) {
            if (!buffer.eof()) {
                buffer >> word;

                if (word.find("https://") != string::npos or word.find("www.") != string::npos) {
                 
                    while (!word.empty()) {
                        if (std::isalpha(word.front(), loc) == 0) {
                            word.erase(0, 1);
                        }
                        else if (std::isalpha(word.back(), loc) == 0) {
                            if (word.back() != '/') {
                                word.pop_back();
                            }
                            else {
                                break;
                            }
                            
                        }
                        else {
                            break;
                        }
                    }

                    urls.push_back(word);
                }
            }
            else {
                break;
            }
        }

        cout << "URL adresai: " << endl << endl;
        for (string i : urls) {
            cout << i << endl;
        }

    }

}
