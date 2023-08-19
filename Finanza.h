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

    void controlloDatiNelFile(Account acPre, Account acPost);

    void stampaMenuAccount();

    void stampaMenuVisualizzazioni(Account account, Carte carte);

    bool cercaAccount(const Account account);

    void creazioneAccount();

    void modificaAccount();

    void eliminaAccount();

    void eseguiOperazionePrelievo(Account account, Carte carta, Account acc, Carte car);

    void eseguiOperazioneDeposito(Account account, Carte carta, Account acc, Carte car);

    void stampaDatiAccount();

    void stampaDatiCarte(Account account);

    void stampaTransazioni(Account account, Carte carta);

    void stampaTransazioniAccount(Account account, Carte carta);

};

#endif //ESAMELABGESTIONE_FINANZA_H
