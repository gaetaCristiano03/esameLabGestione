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
        try {
            if (giorno > 0 && giorno < 32 && mese > 0 && mese < 13 ) {
                this->giorno = giorno;
                this->mese = mese;
                this->anno = anno;
            }
            else {
                throw invalid_argument("Dati non validi, riprovare.");
            }
        } catch (const invalid_argument &e) {
            cerr << "Errore nell'inserimento della data." << endl;
        }
    };

    string stampaData() {
        string line = to_string(giorno) + "-" + to_string(mese) + "-" + to_string(anno);
        return line;
    }

    int getGiorno() {
        return giorno;
    }
};

#endif //ESAMELABGESTIONE_DATA_H
