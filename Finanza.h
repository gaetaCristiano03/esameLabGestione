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

    bool cercaAccount(const Account account);

    void creazioneAccount();

    void modificaAccount();

    void eliminaAccount();

    void eseguiOperazionePrelievo(Account account, Carte carta, Account acc, Carte car);

    void eseguiOperazioneDeposito(Account account, Carte carta, Account acc, Carte car);

};

#endif //ESAMELABGESTIONE_FINANZA_H
