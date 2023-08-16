#ifndef ESAMELABGESTIONE_ACCOUNT_H
#define ESAMELABGESTIONE_ACCOUNT_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Account {
private:
    //vector<Carte> carte;
    string nome, cognome, email;
    unsigned long int numeroTelefono, eta;

public:
    Account();

};

#endif //ESAMELABGESTIONE_ACCOUNT_H
