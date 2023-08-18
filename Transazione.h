#ifndef ESAMELABGESTIONE_TRANSAZIONE_H
#define ESAMELABGESTIONE_TRANSAZIONE_H

#include <string>

using namespace std;

class Transazione {
private:
    int data, importo;
    string giorno;

public:
    Transazione() {};

    Transazione(const int& data, const int& importo, const string& giorno) : data(data), importo(importo), giorno(giorno) {};
};

#endif //ESAMELABGESTIONE_TRANSAZIONE_H
