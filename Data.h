#ifndef ESAMELABGESTIONE_DATA_H
#define ESAMELABGESTIONE_DATA_H

#include <iostream>

using namespace std;

class Data {
private:
    int giorno, mese, anno;

public:
    Data(int giorno, int mese, int anno) : giorno(giorno), mese(mese), anno(anno) {};

    string stampaData() {
        string line = to_string(giorno) + "-" + to_string(mese) + "-" + to_string(anno);
        return line;
    }
};

#endif //ESAMELABGESTIONE_DATA_H
