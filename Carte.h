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
    Carte();

    Carte(const int &numeroConto, const int &dataScadenza, const int &salario, const string &iban);

//Getter & Setter:
    int getNumeroConto() const {
        return numeroConto;
    }

    int getDataScadenza() const {
        return dataScadenza;
    }

    int getSaldo() const {
        return saldo;
    }

    string getIban() const {
        return iban;
    }

};

#endif //ESAMELABGESTIONE_CARTE_H
