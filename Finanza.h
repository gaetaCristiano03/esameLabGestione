#ifndef ESAMELABGESTIONE_FINANZA_H
#define ESAMELABGESTIONE_FINANZA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Account.h"

class Finanza {
private:
    vector <Account> accounts;

public:
    Finanza();

    void inserisciDatiAccount(string &nome, string &cognome, string &email, unsigned long int &num, unsigned long int &eta);

    void stampaMenuAccount();

    virtual bool cercaAccount();

    bool cercaAccount(Account account);

    void creazioneAccount();

    void modificaAccount();

};

#endif //ESAMELABGESTIONE_FINANZA_H
