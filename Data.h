#ifndef ESAMELABGESTIONE_DATA_H
#define ESAMELABGESTIONE_DATA_H

#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

class Data {
private:
    int giorno, mese, anno;

public:
    Data(int giorno, int mese, int anno) {
        controlloData(giorno, mese, anno);
    };

    void controlloData(int giorno, int mese, int anno) {
        if (giorno >= 1 && giorno <= 31 && mese >= 1 && mese <= 12) {
            this->giorno = giorno;
            this->mese = mese;
            this->anno = anno;
            }
        else
            throw invalid_argument("Valori non validi.");
    }

    string stampaData() {
        string line = to_string(giorno) + "-" + to_string(mese) + "-" + to_string(anno);
        return line;
    }
};

#endif //ESAMELABGESTIONE_DATA_H
