#include <iostream>
#include "Finanza.h"

string nome, cognome, email;
unsigned long int numeroTelefono, eta;
bool controlloEsistenza = true;

Finanza :: Finanza() {};

void Finanza :: inserisciDatiAccount(string &nome, string &cognome, string &email, unsigned long int &num, unsigned long int &eta) {
    cout << "INSERIMENTO UTENTE:" << endl;
    cout << " 1. Nome -> ";
    cin >> nome;
    cout << "2. Cognome -> ";
    cin >> cognome;
    cout << "3. Ind. email -> ";
    cin >> email;
    cout << "4. Numero di tel. -> ";
    cin >> num;
    cout << "5. Eta -> ";
    cin >> eta;
}

void Finanza :: stampaMenuAccount() {
    int scelta;

    cout << "GESTIONE UTENTI:" << endl;
    cout << "1. Iscrizione nuovo utente;" << endl;
    cout << "2. Modifica dati di un utente gia' esistente;" << endl;
    cout << "3. Elimina utente." << endl;
    cout << "4. Torna indietro." << endl;

    cout << "Scegli una delle seguenti opzioni -> ";
    cin >> scelta;
    cout << endl;

    while (scelta < 1 || scelta > 4) {
        cout << "Inserimento I/O errato, riprovare." << endl;
        cout << "Scegli una opzione -> ";
        cin >> scelta;
    }
    cout << endl;

    switch(scelta) {
        case 1:
            creazioneAccount();
            break;
        case 2:
            //modificaAccount();
            break;
        case 3:
            //eliminaAccount();
            break;
    }
}

bool Finanza :: cercaAccount() {
    inserisciDatiAccount(nome, cognome, email, numeroTelefono, eta);
    Account account(nome, cognome, email, numeroTelefono, eta);

    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].getNumeroTelefono() == account.getNumeroTelefono())
            return true;
    }
    return false;

}

bool Finanza :: cercaAccount(const Account account) {
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].getNumeroTelefono() == account.getNumeroTelefono())
            return true;
    }
    return false;
}

void Finanza :: creazioneAccount() {
    inserisciDatiAccount(nome, cognome, email, numeroTelefono, eta);
    Account account(nome, cognome, email, numeroTelefono, eta);

    accounts.push_back(account);
    cout << "Creazione utente completata!" << endl;

    ofstream file("Salvataggio_dati.txt", ios::app);

    if(file.is_open()) {
        string line = "Utente -> Nome: " + account.getNome() + ";   Cognome: " + account.getCognome() + ";   Email: "
                      + account.getEmail() + ";   Cellulare: " + to_string(account.getNumeroTelefono()) +
                      ";   Eta: " + to_string(account.getEta()) + ";";

        file << line << endl << endl;

        cout << " Dati inseriti con successo." << endl;
    }
    else cout << "Impossibile aprire il file." << endl;

    file.close();

}

void Finanza :: modificaAccount() {
    inserisciDatiAccount(nome, cognome, email, numeroTelefono, eta);
    Account accountPre(nome, cognome, email, numeroTelefono, eta);
    controlloEsistenza = cercaAccount(accountPre);

    if(controlloEsistenza) {
        cout << endl <<"Ora inserisci i nuovi dati: " << endl;
        inserisciDatiAccount(nome, cognome, email, numeroTelefono, eta);
        Account accountPost(nome, cognome, email, numeroTelefono, eta);

        for(int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getNumeroTelefono() == accountPre.getNumeroTelefono()) {
                accounts[i] = accountPost;
                cout << "Modifica effettuata!" << endl;

                ifstream file("Salvataggio_dati.txt");

                if (file.is_open()) {
                    vector<string> lines;
                    string line;

                    while (getline(file, line)) {
                        if (line == "Utente: Nome: " + accountPre.getNome() + ";   Cognome: " + accountPre.getCognome() + ";   Email: "
                                    + accountPre.getEmail() + ";   Cellulare: " + to_string(accountPre.getNumeroTelefono()) +
                                    ";   Eta: " + to_string(accountPre.getEta()) + ";") {

                            line = "Utente: Nome: " + accountPost.getNome() + ";   Cognome: " + accountPost.getCognome() + ";   Email: "
                                   + accountPost.getEmail() + ";   Cellulare: " + to_string(accountPost.getNumeroTelefono()) +
                                   ";   Eta: " + to_string(accountPost.getEta()) + ";";
                        }
                        lines.push_back(line);
                    }

                    ofstream file("Salvataggio_dati.txt");

                    if (file.is_open()) {
                        for (const auto& line : lines) {
                            file << line << endl;
                        }
                        file.close();
                        cout << " Modifica del file eseguita!" << endl;
                    }
                }
                else cout << "Errore nell'apertura del file." << endl;
                break;
            }
        }
    }
    else cout << "Account non trovato, controllare dati." << endl;
    controlloEsistenza = true;
}

void Finanza :: eliminaAccount() {
    inserisciDatiAccount(nome, cognome, email, numeroTelefono, eta);
    Account account(nome, cognome, email, numeroTelefono, eta);

    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].getNumeroTelefono() == account.getNumeroTelefono()) {
            auto pos = i + accounts.begin();
            accounts.erase(pos);

            cout << "Eliminazione completata!" << endl;

            ifstream file("Salvataggio_dati.txt");

            if (file.is_open()) {
                vector<string> lines;
                string line;

                while (getline(file, line)) {
                    if (line != "Utente: Nome: " + account.getNome() + ";   Cognome: " + account.getCognome() + ";   Email: "
                                + account.getEmail() + ";   Cellulare: " + to_string(account.getNumeroTelefono()) +
                                ";   Eta: " + to_string(account.getEta()) + ";") {
                        lines.push_back(line);
                    }
                }
                file.close();

                ofstream file("Salvataggio_dati.txt");

                if (file.is_open()) {
                    for (const auto& line : lines) {
                        file << line << endl;
                    }

                    file.close();

                    cout << "Le righe sono state eliminate dal file." << endl;
                }
            }
            break;
        }
    }
    cout << "Account non trovato, riprovare." << endl;

}