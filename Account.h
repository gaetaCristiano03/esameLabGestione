#ifndef ESAMELABGESTIONE_ACCOUNT_H
#define ESAMELABGESTIONE_ACCOUNT_H

#include <string>
#include <vector>
#include <fstream>
#include "Carte.h"

using namespace std;

class Account {
private:
    vector<Carte> carte;
    string nome, cognome, email;
    unsigned long int numeroTelefono, eta;

public:
    Account();

    Account(const string &nome, const string &cognome, const string &email, const unsigned long int &numeroTelefono, const unsigned long int &eta);

    //Getter and Setter
    string getNome() const {
        return nome;
    }

    string getCognome() const {
        return cognome;
    }

    string getEmail() const {
        return email;
    }

    unsigned long int getNumeroTelefono() const {
        return numeroTelefono;
    }

    unsigned long int getEta() const {
        return eta;
    }

    const vector<Carte> &getCarte() const {
        return carte;
    }

};

#endif //ESAMELABGESTIONE_ACCOUNT_H