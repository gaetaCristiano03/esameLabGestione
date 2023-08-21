#include <iostream>
#include <string>
#include "Carte.h"

using namespace std;

Carte :: Carte() {};

Carte :: Carte(const int &numeroConto, const int &saldo, const string &iban) : numeroConto(numeroConto), saldo(saldo), iban(iban) {};

bool Carte :: cercaTransazione(Transazione transazione) {
    for(int i = 0; i < transazioni.size(); i++) {
        if(transazioni[i].getGiorno() == transazione.getGiorno()) {
            if(transazioni[i].getData() == transazione.getData()) {
                if(transazioni[i].getImporto() == transazione.getImporto()) {
                    if(transazioni[i].getCodice() == transazione.getCodice())
                        return true;
                }
            }
        }
    }
    return false;
}

void Carte :: inserisciDatiTransazione(int &date, int &importo, int& codice, string &giorno, string& causale) {
    cout << " 1. Data transazione -> ";
    cin >> date;
    cout << "2. Giorno -> ";
    cin >> giorno;
    cout << "3. Importo -> ";
    cin >> importo;
    cout << "4. Causale -> ";
    cin >> causale;
    cout << "5. Codice -> ";
    cin >> codice;
}

void Carte :: inserisciTransazione(Transazione transazione) {
    transazioni.push_back(transazione);
}

void Carte :: sostituisciTransazione(int indice, Transazione transazione) {
    transazioni[indice] = transazione;
}

void Carte ::eliminaTransazione(int indice) {
    auto i = transazioni.begin() + indice;
    transazioni.erase(i);
}