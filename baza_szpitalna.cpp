#include "baza_szpitalna.h"
#include <algorithm>
#include <iostream>

BazaSzpitalna::BazaSzpitalna() {
    dodajPacjenta({"Jan", "Kowalski", 30, 'M', {"Grypa", "Katar"}});
    dodajPacjenta({"Anna", "Nowak", 25, 'K', {"Ból głowy", "Kaszel"}});
    dodajPacjenta({"Michał", "Wiśniewski", 40, 'M', {"Astma", "Katar"}});
}

BazaSzpitalna::~BazaSzpitalna() {}

void BazaSzpitalna::dodajPacjenta(const Pacjent& pacjent) {
    pacjenci.push_back(pacjent);
}

void BazaSzpitalna::usunPacjenta(int indeks) {
    if (indeks >= 0 && indeks < pacjenci.size()) {
        pacjenci.erase(pacjenci.begin() + indeks);
    }
}

void BazaSzpitalna::wyswietlPacjentow() const {
    std::cout << "Lista pacjentów:\n";
    for (size_t i = 0; i < pacjenci.size(); ++i) {
        std::cout << "ID: [" << i << "] ";
        std::cout << "Imię: " << pacjenci[i].imie << ", Nazwisko: " << pacjenci[i].nazwisko
                  << ", Wiek: " << pacjenci[i].wiek << ", Płeć: " << pacjenci[i].plec
                  << ", Historia chorób [" << pacjenci[i].historiaChorob.size() << "]: ";
        for (const auto& choroba : pacjenci[i].historiaChorob) {
            std::cout << choroba << ", ";
        }
        std::cout << std::endl;
    }
}


void BazaSzpitalna::sortujPacjentowWgChorob() {
    std::sort(pacjenci.begin(), pacjenci.end(), [](const Pacjent& a, const Pacjent& b) {
        return a.historiaChorob.size() > b.historiaChorob.size();
    });
}