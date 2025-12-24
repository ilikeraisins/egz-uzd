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

void table(map<string, vector<int>> map) {
    cout << left << setw(15) << "Word" << " | " << setw(30) << "Lines" << endl;

    for (int i = 0; i < 60; i++) {
        cout << "-";
    }
    cout << endl;

    for (auto i : map) {
        if (i.second.size() > 1) {
            cout << left << setw(15) << i.first << " | ";
            for (int j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}