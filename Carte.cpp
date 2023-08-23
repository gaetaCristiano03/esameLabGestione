#include <iostream>
#include <string>
#include "Carte.h"

using namespace std;

Carte :: Carte() {};

Carte :: Carte(const int &numeroConto, const int &saldo, const string &iban) : numeroConto(numeroConto), saldo(saldo), iban(iban) {};

bool Carte :: cercaTransazione(Transazione transazione) {
    for(int i = 0; i < transazioni.size(); i++) {
        if(transazioni[i].getImporto() == transazione.getImporto()) {
            if(transazioni[i].getCausale() == transazione.getCausale()) {
                if (transazioni[i].getCodice() == transazione.getCodice())
                    return true;
            }
        }
    }
    return false;
}

void Carte :: inserisciDatiTransazione(Data &date, int &importo, int& codice, string& causale) {
    int giorno, mese, anno;
    cout << " 1. Giorno -> ";
    cin >> giorno;
    cout << "2. Mese -> ";
    cin >> mese;
    cout<< "3. Anno -> ";
    cin >> anno;
    cout << "4. Importo -> ";
    cin >> importo;
    cout << "5. Causale -> ";
    cin >> causale;
    cout << "6. Codice -> ";
    cin >> codice;

    date = Data(giorno, mese, anno);
}

void Carte :: inserisciTransazione(Transazione transazione) {
    transazioni.push_back(transazione);
}

void Carte :: sostituisciTransazione(int indice, Transazione transazione) {
    transazioni[indice] = transazione;
}

void Carte :: eliminaTransazione(int indice) {
    auto i = transazioni.begin() + indice;
    transazioni.erase(i);
}