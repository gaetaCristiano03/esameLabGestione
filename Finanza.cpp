#include <iostream>
#include "Finanza.h"

string nome, cognome, email, giorno;
unsigned long int numeroTelefono, eta, date, importo;
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
            modificaAccount();
            break;
        case 3:
            eliminaAccount();
            break;
    }
}

void Finanza :: stampaMenuVisualizzazioni(Account account, Carte carta) {
    int scelta;

    cout << "VISUALIZZAZIONE DATI:" << endl;
    cout << "1. Dati di tutti gli utenti;" << endl;
    cout << "2. Carte di ogni utente;" << endl;
    cout << "3. Tutte le transazioni;" << endl;
    cout << "4. Transazione di ogni utente." << endl;

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
            stampaDatiAccount();
            break;
        case 2:
            stampaDatiCarte(account);
            break;
        case 3:
            stampaTransazioni(account, carta);
            break;
        case 4:
            stampaTransazioniAccount(account, carta);
            break;
    }

}

bool Finanza :: cercaAccount(const Account account) {
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].getNumeroTelefono() == account.getNumeroTelefono())
            cout << endl;
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

    if(controlloEsistenza == true) {
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
                        if (line == "Utente -> Nome: " + accountPre.getNome() + ";   Cognome: " + accountPre.getCognome() + ";   Email: "
                                    + accountPre.getEmail() + ";   Cellulare: " + to_string(accountPre.getNumeroTelefono()) +
                                    ";   Eta: " + to_string(accountPre.getEta()) + ";") {

                            line = "Utente -> Nome: " + accountPost.getNome() + ";   Cognome: " + accountPost.getCognome() + ";   Email: "
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
                    if (line != "Utente -> Nome: " + account.getNome() + ";   Cognome: " + account.getCognome() + ";   Email: "
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
        else cout << "Account non trovato, riprovare." << endl;
    }
}

void Finanza :: eseguiOperazionePrelievo(Account account, Carte carta, Account acc, Carte car) {
    carta.inserisciDatiTransazione(date, importo, giorno);
    Transazione transazione(date, importo, giorno);

    for(int i = 0; i < accounts.size(); i++) {
        if(acc.getNumeroTelefono() == accounts[i].getNumeroTelefono()) {

            for(int j = 0; j < account.getCarte().size(); j++) {
                if(carta.getIban() == account.getCarte()[j].getIban()) {

                    if(account.getCarte()[j].getSaldo() > transazione.getImporto()) {
                        carta.inserisciTransazione(transazione);
                        account.setSaldo(1, j, transazione.getImporto());
                    }
                    else cout << "Errore nell'operazione." << endl;

                    ofstream file("Salvataggio_dati.txt", ios::app);

                    if (file.is_open()) {

                        string lineNameUser = "Prelievo su carta di " + account.getNome() + " " + account.getCognome() + ":";
                        file << lineNameUser << endl;

                        string lineCont = " Numero carta -> " + to_string(carta.getNumeroConto()) + ", Data scadenza -> " +
                                          to_string(carta.getDataScadenza()) + ", Salario -> " + to_string(carta.getSaldo())
                                          + ", Iban -> " + carta.getIban() + ";";
                        file << lineCont << endl;

                        string lineTrans = " Data -> " + to_string(transazione.getData()) + ", Giorno -> " + transazione.getGiorno()
                                           + ", Importo -> " + to_string(transazione.getImporto()) + ";";
                        file << lineTrans << endl << endl;

                        cout << "Transazione completata!" << endl;
                    }
                    else cout << "Impossibile aprire il file." << endl;

                    file.close();
                }
            }

        }
    }

}

void Finanza :: eseguiOperazioneDeposito(Account account, Carte carta, Account acc, Carte car) {
    carta.inserisciDatiTransazione(date, importo, giorno);
    Transazione transazione(date, importo, giorno);

    for(int i = 0; i < accounts.size(); i++) {
        if (acc.getNumeroTelefono() == accounts[i].getNumeroTelefono()) {

            for (int j = 0; j < account.getCarte().size(); j++) {
                if (carta.getIban() == account.getCarte()[j].getIban()) {
                    carta.inserisciTransazione(transazione);
                    account.setSaldo(2, j, transazione.getImporto());

                    ofstream file("Salvataggio_dati.txt", ios::app);

                    if (file.is_open()) {

                        string lineNameUser = "Deposito su carta di " + account.getNome() + " " + account.getCognome() + ":";
                        file << lineNameUser << endl;

                        string lineCont = " Numero carta -> " + to_string(carta.getNumeroConto()) + ", Data scadenza -> " +
                                          to_string(carta.getDataScadenza()) + ", Salario -> " + to_string(carta.getSaldo())
                                          + ", Iban -> " + carta.getIban() + ";";
                        file << lineCont << endl;

                        string lineTrans = " Data -> " + to_string(transazione.getData()) +  ", Giorno -> " + transazione.getGiorno()
                                           + ", Importo -> " + to_string(transazione.getImporto()) + ";";
                        file << lineTrans << endl << endl;

                        cout << "Transazione completata!" << endl;
                    }
                    else cout << "Impossibile aprire il file." << endl;

                    file.close();
                }
            }

        }
    }
}

void Finanza :: stampaDatiAccount() {
    int indice = 1;
    cout << "STAMPA DATI DI TUTTI GLI UTENTI:" << endl;

    for(int i = 0; i < accounts.size(); i++) {
        indice += i;
        cout << indice << "' " << accounts[i].getNome() << " " << accounts[i].getCognome() << ", " << accounts[i].getEmail()
             << ", " << accounts[i].getEta() << ", " << accounts[i].getNumeroTelefono() << ";" << endl;
    }

}

void Finanza :: stampaDatiCarte(Account account) {
    int indice = 1;

    for(int i = 0; i < accounts.size(); i++) {
        indice += i;
        cout << indice << "' " << accounts[i].getNome() << " " << accounts[i].getCognome() << ":" << endl;

        for(int j = 0; j < account.getCarte().size(); j++) {
            indice += j;
            cout << "  " << indice << "' " << account.getCarte()[j].getNumeroConto() << ", " << account.getCarte()[j].getIban()
                 << ", " << account.getCarte()[j].getDataScadenza() << ", " << account.getCarte()[j].getSaldo() << ";" << endl;
        }
        indice = i + 1;
    }
}

void Finanza :: stampaTransazioni(Account account, Carte carta) {
    int indice = 1;

    for(int i = 0; i < accounts.size(); i++) {
        for(int j = 0; j < account.getCarte().size(); j++) {
            for(int k = 0; k < carta.getTransazioni().size(); k++) {
                cout << "  " << indice << "' " << carta.getTransazioni()[k].getData() << ", " << carta.getTransazioni()[k].getImporto()
                     << ", " << carta.getTransazioni()[k].getGiorno() << ";" << endl;
                indice++;
            }
        }
    }
}

void Finanza :: stampaTransazioniAccount(Account account, Carte carta) {
    int indice = 1;

    for(int i = 0; i < accounts.size(); i++) {
        indice += i;
        cout << indice << "' " << accounts[i].getNome() << " " << accounts[i].getCognome() << ":" << endl;

        for(int j = 0; j < account.getCarte().size(); j++) {
            indice += j;
            cout << "  " << indice << "' " << account.getCarte()[j].getNumeroConto() << ", " << account.getCarte()[j].getIban() << ";" << endl;

            for(int k = 0; k < carta.getTransazioni().size(); k++) {
                indice += k;
                cout << "  " << indice << "' " << carta.getTransazioni()[k].getData() << ", " << carta.getTransazioni()[k].getImporto()
                     << ", " << carta.getTransazioni()[k].getGiorno() << ";" << endl;
            }
            indice = j + 1;
        }
        indice = i + 1;
    }
}