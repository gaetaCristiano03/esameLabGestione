#include <iostream>
#include <string>
#include "Carte.h"

using namespace std;

Carte :: Carte() {};

Carte :: Carte(const int &numeroConto, const int &dataScadenza, const int &saldo, const string &iban) : numeroConto(numeroConto),
                                                                                                          dataScadenza(dataScadenza), saldo(saldo), iban(iban) {};

void Carte::inserisciDatiTransazione(int date, int importo, string giorno) {
    cout << " 1. Data transazione -> ";
    cin >> date;
    cout << "2. Giorno -> ";
    cin >> giorno;
    cout << "3. Importo -> ";
    cin >> importo;
}