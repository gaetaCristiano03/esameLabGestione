#ifndef ESAMELABGESTIONE_DATA_H
#define ESAMELABGESTIONE_DATA_H

#include <iostream>

using namespace std;

class Data {
private:
    int giorno, mese, anno;

public:
    Data(int giorno, int mese, int anno) {
        while (controlloData(giorno, mese, anno) == false) {
            cout << "Inserimento errato nella data, riprovare:" << endl;
            cout << " Giorno -> ";
            cin >> giorno;
            cout << "Mese -> ";
            cin >> mese;
            cout << "Anno -> ";
            cin >> anno;
        }

        this -> giorno = giorno;
        this -> mese = mese;
        this -> anno = anno;
    };

    bool controlloData(int giorno, int mese, int anno) {
        if(giorno < 1 || giorno > 31 || mese < 1 || mese > 12)
            return false;
        return true;
    }

    string stampaData() {
        string line = to_string(giorno) + "-" + to_string(mese) + "-" + to_string(anno);
        return line;
    }

    int getGiorno() {
        return giorno;
    }
};

#endif //ESAMELABGESTIONE_DATA_H
