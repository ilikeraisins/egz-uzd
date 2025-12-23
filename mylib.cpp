#include "main.h"

std::stringstream failo_skaitimas(string failo_vardas) {
    std::stringstream buffer;
    std::ifstream fl(failo_vardas);
    buffer << fl.rdbuf();
    fl.close();
    return buffer;