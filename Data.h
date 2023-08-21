#ifndef ESAMELABGESTIONE_DATA_H
#define ESAMELABGESTIONE_DATA_H

#include <iostream>

using namespace std;

class Data {
private:
    int giorno, mese, anno;

public:
    void getData() {
        cout << giorno << "-" << mese << "-" << anno;
    }
};

#endif //ESAMELABGESTIONE_DATA_H
