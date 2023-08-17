#include <iostream>
#include <string>
#include "Carte.h"

using namespace std;

Carte :: Carte() {};

Carte :: Carte(const int &numeroConto, const int &dataScadenza, const int &saldo, const string &iban) : numeroConto(numeroConto),
                                                                                                          dataScadenza(dataScadenza), saldo(saldo), iban(iban) {};