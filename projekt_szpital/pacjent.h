#ifndef PACJENT_H
#define PACJENT_H

#include <string>
#include <vector>

struct Pacjent {
    std::string imie;
    std::string nazwisko;
    int wiek;
    char plec;
    std::vector<std::string> historiaChorob;
};

#endif // PACJENT_H