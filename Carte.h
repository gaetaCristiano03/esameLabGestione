#ifndef ESAMELABGESTIONE_CARTE_H
#define ESAMELABGESTIONE_CARTE_H

#include <string>
#include <vector>
#include "Transazione.h"

using namespace std;

class Carte {
private:
    vector<Transazione> transazioni;
    int numeroConto, saldo;
    string iban;

public:
    Carte();

    Carte(int numeroConto, int saldo, const string &iban);

    void inserisciDatiTransazione(Data &date, int &importo, int& codice, string& causale);

    bool cercaTransazione(const Transazione &transazione);

    void inserisciTransazione(Transazione transazione);

    void sostituisciTransazione(int indice, Transazione transazione);

    void eliminaTransazione(int indice);

    //Getter & Setter:
    int getNumeroConto() const {
        return numeroConto;
    }

    int getSaldo() const {
        return saldo;
    }

    void setSaldo(int saldo) {
        this->saldo = saldo;
    }

    string getIban() const {
        return iban;
    }

    const vector<Transazione> &getTransazioni() const {
        return transazioni;
    }

    void setTransazioni(const Transazione transazione) {
        transazioni.push_back(transazione);
    }

};

#endif //ESAMELABGESTIONE_CARTE_H
