#ifndef ESAMELABGESTIONE_TRANSAZIONE_H
#define ESAMELABGESTIONE_TRANSAZIONE_H

#include <string>

using namespace std;

class Transazione {
private:
    int data, importo, codice;
    string giorno, causale;
    bool sceltaOperazione;

public:
    Transazione() {};

    Transazione(const int& data, const int& importo, const string& giorno, const bool& sceltaOperazione, const int& codice,
                const string& causale) : data(data), importo(importo), giorno(giorno), sceltaOperazione(sceltaOperazione),
                codice(codice), causale(causale) {};

    //Getter and Setter
    int getData() const {
        return data;
    }

    int getImporto() const {
        return importo;
    }

    int getCodice() const {
        return codice;
    }

    string getGiorno() const {
        return giorno;
    }

    string getCausale() const {
        return causale;
    }

    bool getBool() const {
        return sceltaOperazione;
    }


};

#endif //ESAMELABGESTIONE_TRANSAZIONE_H
