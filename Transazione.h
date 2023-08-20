#ifndef ESAMELABGESTIONE_TRANSAZIONE_H
#define ESAMELABGESTIONE_TRANSAZIONE_H

#include <string>

using namespace std;

class Transazione {
private:
    int data, importo;
    string giorno;
    bool sceltaOperazione;

public:
    Transazione() {};

    Transazione(const int& data, const int& importo, const string& giorno, const bool& sceltaOperazione) : data(data), importo(importo), giorno(giorno), sceltaOperazione(sceltaOperazione) {};

    //Getter and Setter
    int getData() const {
        return data;
    }

    int getImporto() const {
        return importo;
    }

    string getGiorno() const {
        return giorno;
    }

    bool getBool() const {
        return sceltaOperazione;
    }
};

#endif //ESAMELABGESTIONE_TRANSAZIONE_H
