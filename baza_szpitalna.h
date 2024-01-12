#ifndef BAZASZPITALNA_H
#define BAZASZPITALNA_H

#include "pacjent.h"
#include <vector>

class BazaSzpitalna {
public:
    BazaSzpitalna();
    ~BazaSzpitalna();

    void dodajPacjenta(const Pacjent& pacjent);
    void usunPacjenta(int indeks);
    void wyswietlPacjentow() const;
    void sortujPacjentowWgChorob();

private:
    std::vector<Pacjent> pacjenci;
};

#endif //  BAZASZPITALNA_H