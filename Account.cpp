#include <iostream>
#include "Account.h"

using namespace std;

int numeroConto, dataScadenza, saldo;
string iban, nome, cognome, email;
unsigned long int numeroTelefono, eta;
bool controlloEsistenza = false;

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

void Account :: stampaMenuCarte(Finanza finanza) {
    int scelta;

    cout << "GESTIONE CONTI/CARTE:" << endl;
    cout << "1. Aggiungi una nuova carta;" << endl;
    cout << "2. Modifica una carta gia' esistente;" << endl;
    cout << "3. Elimina una carta." << endl;
    cout << "4. Torna indietro." << endl;

    cout << "Scegli una delle seguenti opzioni -> ";
    cin >> scelta;
    cout << endl;

    while (scelta < 1 || scelta > 5) {
        cout << "Inserimento I/O errato, riprovare." << endl;
        cout << "Scegli una opzione -> ";
        cin >> scelta;
    }
    cout << endl;

    switch(scelta) {
        case 1:
            creazioneCarta(finanza);
            break;
        case 2:
            modificaCarta();
            break;
        case 3:
            eliminaCarta();
            break;
    }

}

void Account :: creazioneCarta(Finanza finanza) {
    Account account;

    while(controlloEsistenza == false) {
        finanza.inserisciDatiAccount(Account::nome, Account::cognome, Account::email, Account::numeroTelefono, Account::eta);
        account = Account(Account::nome, Account::cognome, Account::email, Account::numeroTelefono, Account::eta);
        controlloEsistenza = finanza.cercaAccount(account);
        cout << endl;
    }

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

