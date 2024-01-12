#include "baza_szpitalna.h"
#include "baza_szpitalna.cpp"
#include "pacjent.h"
#include <iostream>

using namespace std;

void wyswietlMenu(BazaSzpitalna& bazaSzpitalna) {
    int wybor;

    do {
        cout << endl << endl << endl;
        cout << "        Menu        " << endl;
        cout << "====================" << endl << endl;
        cout << "1. Dodaj pacjenta" << endl;
        cout << "2. Usun pacjenta" << endl;
        cout << "3. Wyswietl pacjentow" << endl;
        cout << "4. Sortuj pacjentow wedlog ilosci chrob" << endl;
        cout << "0. Zakoncz dzialanie programu" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1: {
                cout << "   Dodaj pacjenta   " << endl;
                cout << "====================" << endl << endl;
                Pacjent nowyPacjent;
                cout << "Imię: ";
                cin >> nowyPacjent.imie;
                cout << "Nazwisko: ";
                cin >> nowyPacjent.nazwisko;
                cout << "Wiek: ";
                cin >> nowyPacjent.wiek;
                cout << "Płeć (M/K): ";
                cin >> nowyPacjent.plec;

                int iloscChorob;
                cout << "Ilość chorób: ";
                cin >> iloscChorob;

                for (int i = 0; i < iloscChorob; ++i) {
                    string choroba;
                    cout << "Choroba " << i + 1 << ": ";
                    cin >> choroba;
                    nowyPacjent.historiaChorob.push_back(choroba);
                }

                bazaSzpitalna.dodajPacjenta(nowyPacjent);
                break;
            }
            case 2: {
                int indeks;
                cout << "    Usun pacjenta   " << endl;
                cout << "====================" << endl << endl;
                cout << "Podaj indeks pacjenta do usunięcia: ";
                cin >> indeks;
                bazaSzpitalna.usunPacjenta(indeks);
                break;
            }
            case 3:
                cout << " Wyswietl pacjentow " << endl;
                cout << "====================" << endl << endl;
                bazaSzpitalna.wyswietlPacjentow();
                break;
            case 4:
                cout << "  Sortuj pacjentow  " << endl;
                cout << "====================" << endl << endl;
                bazaSzpitalna.sortujPacjentowWgChorob();
                cout << "Pacjenci posortowani wg chorób." << endl;
                bazaSzpitalna.wyswietlPacjentow();
                break;
            case 0:
                cout << "Zakończono program." << endl;
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }
    } while (wybor != 0);
}

int main() {
    BazaSzpitalna bazaSzpitalna;
    wyswietlMenu(bazaSzpitalna);

    return 0;
}
