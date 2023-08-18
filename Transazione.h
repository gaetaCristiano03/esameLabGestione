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

    //Getter and Setter
    int getData() const {
        return data;
    }

    void setData(int data) {
        this->data = data;
    }

    int getImporto() const {
        return importo;
    }

    void setImporto(int importo) {
        this->importo = importo;
    }

    string getGiorno() const {
        return giorno;
    }

    void setGiorno(string giorno) {
        this->giorno = giorno;
    }
};

#endif //ESAMELABGESTIONE_TRANSAZIONE_H
