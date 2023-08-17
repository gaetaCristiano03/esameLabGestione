#include <iostream>
#include "Account.h"

using namespace std;

int numeroConto, dataScadenza, saldo;
string iban;

Account :: Account() {};

Account :: Account(const string &nome, const string &cognome, const string &email, const unsigned long int &numeroTelefono, const unsigned long int &eta) :
        nome(nome), cognome(cognome), email(email), numeroTelefono(numeroTelefono), eta(eta){};

void inserisciDatiCarta(int &numeroConto, int &dataScadenza, int &saldo, string &iban) {
    cout << "INSERIMENTO DATI CARTA:" << endl;
    cout << " 1. Numero del conto -> ";
    cin >> numeroConto;
    cout << "2. Data di scadenza -> ";
    cin >> dataScadenza;
    cout << "3. Saldo -> ";
    cin >> saldo;
    cout << "4. Iban -> ";
    cin >> iban;
}

void Account :: creazioneCarta(Account account) {

    inserisciDatiCarta(numeroConto, dataScadenza, saldo, iban);
    Carte carta(numeroConto, dataScadenza, saldo, iban);

    carte.push_back(carta);
    cout << "Creazione carta completata!" << endl;

    ofstream file("Salvataggio_dati.txt", ios::app);

    if (file.is_open()) {
        string lineNameUser = "Conto di " + account.getNome() + " " + account.getCognome() + ":";
        file << lineNameUser << endl;
        string lineCont = " Numero carta -> " + to_string(carta.getNumeroConto()) + ", Data scadenza -> " +
                          to_string(carta.getDataScadenza()) + ", Salario -> " + to_string(carta.getSaldo())
                          + ", Iban -> " + carta.getIban() + ";";
        file << lineCont << endl << endl;
    }
    else cout << "Impossibile aprire il file." << endl;

    file.close();
}

void Account :: modificaCarta() {}

