#ifndef ESAMELABGESTIONE_DATA_H
#define ESAMELABGESTIONE_DATA_H

#include <iostream>

using namespace std;

class Data {
private:
    int giorno, mese, anno;

public:
    Data(int giorno, int mese, int anno) {
        bool control = false;

        if(giorno > 0 && giorno < 32 && mese > 0 && mese < 13 && anno > 1979 && anno < 2024) {
            control = true;
        }

        while(control == false) {
            cout << "Inserimento errato nella data, riprovare:" << endl;
            cout << " Giorno -> ";
            cin >> giorno;
            cout << "Mese -> ";
            cin >> mese;
            cout << "Anno -> ";
            cin >> anno;

            if(giorno >= 1 && giorno <=31 && mese >= 1 && mese <= 12 && anno >= 1980 && anno <= 2023) {
                control = true;
            }
        }

        this -> giorno = giorno;
        this -> mese = mese;
        this -> anno = anno;

    };

    string stampaData() {
        string line = to_string(giorno) + "-" + to_string(mese) + "-" + to_string(anno);
        return line;
    }
};

#endif //ESAMELABGESTIONE_DATA_H
