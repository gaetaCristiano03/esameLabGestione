#ifndef ESAMELABGESTIONE_CARTE_H
#define ESAMELABGESTIONE_CARTE_H

#include <string>
#include <vector>
#include "Transazione.h"

using namespace std;

class Carte {
private:
    vector<Transazione> transazioni;
    int numeroConto, dataScadenza, saldo;
    string iban;

public:
    Carte() {};

};

#endif //ESAMELABGESTIONE_CARTE_H
