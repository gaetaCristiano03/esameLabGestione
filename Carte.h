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

    Carte(const int &numeroConto, const int &dataScadenza, const int &saldo, const string &iban);

    void inserisciDatiTransazione(int &date, int &importo, string &giorno);

    void inserisciTransazione(Transazione transazione);

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

    void setSaldo(int saldo) {
        this->saldo = saldo;
    }

    void setSal(int sal) {
        this->saldo = sal;
    }

    string getIban() const {
        return iban;
    }

    const vector<Transazione> &getTransazioni() const {
        return transazioni;
    }

};

#endif //ESAMELABGESTIONE_CARTE_H
