#ifndef ESAMELABGESTIONE_TRANSAZIONE_H
#define ESAMELABGESTIONE_TRANSAZIONE_H

#include <string>
#include "Data.h"

using namespace std;

class Transazione {
private:
    int importo, codice;
    string causale;
    bool sceltaOperazione;
    Data data;

public:
    Transazione() {};

    Transazione(const Data& data, const int& importo, const bool& sceltaOperazione, const int& codice,
                const string& causale) : data(data), importo(importo), sceltaOperazione(sceltaOperazione),
                codice(codice), causale(causale) {};

    //Getter and Setter
    Data getData() const {
        return data;
    }

    int getImporto() const {
        return importo;
    }

    int getCodice() const {
        return codice;
    }

    string getCausale() const {
        return causale;
    }

    bool getBool() const {
        return sceltaOperazione;
    }


};

#endif //ESAMELABGESTIONE_TRANSAZIONE_H
