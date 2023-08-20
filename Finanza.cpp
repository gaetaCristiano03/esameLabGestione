#include <iostream>
#include "Finanza.h"

string nome, cognome, email, giorno;
unsigned long int numeroTelefono, eta;
int date, importo;
bool controlloEsistenza;

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

void Finanza :: controlloDatiNelFile(Account accountPre, Account accountPost) {
    ifstream file("Salvataggio_dati.txt");

    if (file.is_open()) {
        vector<string> lines;
        string line;

        while (getline(file, line)) {
            if (line == "Conto di " + accountPre.getNome() + " " + accountPre.getCognome() + ":") {
                line = "Conto di " + accountPost.getNome() + " " + accountPost.getCognome() + ":";
            }
            lines.push_back(line);
        }

        ofstream file("Salvataggio_dati.txt");

        for (const auto &line: lines) {
            file << line << endl;
        }
        file.close();
    }
}

void Finanza :: controlloDatiNelFileTrans(Account acPre, Account acPost) {
    ifstream file("Salvataggio_dati.txt");

    if (file.is_open()) {
        vector<string> lines;
        string line;

        while (getline(file, line)) {
            if (line == "Prelievo su carta di " + acPre.getNome() + " " + acPre.getCognome() + ":")
                line = "Prelievo su carta di " + acPost.getNome() + " " + acPost.getCognome() + ":";

            if(line == "Deposito su carta di " + acPre.getNome() + " " + acPre.getCognome() + ":")
                line = "Deposito su carta di " + acPost.getNome() + " " + acPost.getCognome() + ":";
            lines.push_back(line);
        }

        ofstream file("Salvataggio_dati.txt");

        for (const auto &line: lines) {
            file << line << endl;
        }
        file.close();
        cout << " Modifica del file eseguita!" << endl;
    }
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
        if(accounts[i].getNome() == account.getNome()) {
            if(accounts[i].getCognome() == account.getCognome()) {
                if(accounts[i].getEmail() == account.getEmail()) {
                    if(accounts[i].getEta() == account.getEta()) {
                        if(accounts[i].getNumeroTelefono() == account.getNumeroTelefono())
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

void Finanza :: creazioneAccount() {
    inserisciDatiAccount(nome, cognome, email, numeroTelefono, eta);
    Account account(nome, cognome, email, numeroTelefono, eta);

    controlloEsistenza = cercaAccount(account);

    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].getNumeroTelefono() == account.getNumeroTelefono())
            controlloEsistenza = true;
    }

    if(controlloEsistenza == false) {
        accounts.push_back(account);
        cout << "Creazione utente completata!" << endl;

        ofstream file("Salvataggio_dati.txt", ios::app);

        if (file.is_open()) {
            string line =
                    "Utente -> Nome: " + account.getNome() + ";   Cognome: " + account.getCognome() + ";   Email: "
                    + account.getEmail() + ";   Cellulare: " + to_string(account.getNumeroTelefono()) +
                    ";   Eta: " + to_string(account.getEta()) + ";";

            file << line << endl << endl;

            cout << " Dati inseriti con successo." << endl;
        }
        else cout << "Impossibile aprire il file." << endl;

        file.close();
    }
    else cout << "Account gia' esistente, cambiare dati." << endl;

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

                    for (const auto& line : lines) {
                        file << line << endl;
                    }
                    file.close();

                    controlloDatiNelFile(accountPre, accountPost);
                    controlloDatiNelFileTrans(accountPre, accountPost);
                }
                else
                    cout << "Errore nell'apertura del file." << endl;
                break;
            }
        }
    }
    else
        cout << "Account non trovato, controllare dati." << endl;
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

void Finanza :: eseguiOperazione(Account &account, Carte &carta, Account acc, Carte car, int scelta) {
    carta.inserisciDatiTransazione(date, importo, giorno);
    Transazione transazione;
    string lineNameUser;
    int num;

    if(scelta == 1)
        transazione = Transazione(date, importo, giorno, true);   //PRELIEVO
    else
        transazione = Transazione(date, importo, giorno, false); //DEPOSITO

    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i].getNumeroTelefono() == acc.getNumeroTelefono()) {

            for(int j = 0; j < account.getCarte().size(); j++) {
                if(account.getCarte()[j].getIban() == car.getIban()) {

                    if(transazione.getBool() == true) {
                        if (account.getCarte()[j].getSaldo() > transazione.getImporto()) {
                            carta.inserisciTransazione(transazione);
                            num = account.getCarte()[j].getSaldo() - transazione.getImporto();
                            car.setSaldo(num);
                            account.cambiaSalario(j, car);

                        } else cout << "Errore nell'operazione, credito insuffiente." << endl;
                    }
                    else {
                        num = account.getCarte()[j].getSaldo() + transazione.getImporto();
                        car.setSaldo(num);
                        account.cambiaSalario(j, car);
                    }

                    ofstream file("Salvataggio_dati.txt", ios::app);

                    if (file.is_open()) {
                        if(transazione.getBool() == true)
                            lineNameUser = "Prelievo su carta di " + acc.getNome() + " " + acc.getCognome() + ":";
                        else
                            lineNameUser = "Deposito su carta di " + account.getNome() + " " + account.getCognome() + ":";

                        file << lineNameUser << endl;

                        string lineCont = " Numero carta -> " + to_string(car.getNumeroConto()) + ", Data scadenza -> " +
                                          to_string(car.getDataScadenza()) + ", Salario -> " + to_string(car.getSaldo())
                                          + ", Iban -> " + car.getIban() + ";";
                        file << lineCont << endl;

                        string lineTrans = " Data -> " + to_string(transazione.getData()) + ", Giorno -> " + transazione.getGiorno()
                                           + ", Importo -> " + to_string(transazione.getImporto()) + ";";
                        file << lineTrans << endl << endl;

                        cout << "Transazione completata!" << endl;
                    }

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
        cout << indice << "-> [" << accounts[i].getNome() << " " << accounts[i].getCognome() << ", " << accounts[i].getEmail()
             << ", " << accounts[i].getEta() << ", " << accounts[i].getNumeroTelefono() << "];" << endl;
    }

}

void Finanza :: stampaDatiCarte(Account account) {
    int indice = 1;
    cout << "STAMPA DATI DELLE CARTE PER OGNI UTENTE:" << endl;

    for(int i = 0; i < accounts.size(); i++) {
        indice += i;
        cout << indice << ". " << accounts[i].getNome() << " " << accounts[i].getCognome() << ":" << endl;

        for(int j = 0; j < account.getCarte().size(); j++) {
            indice += j;
            cout << "  " << indice << "-> [" << account.getCarte()[j].getNumeroConto() << ", " << account.getCarte()[j].getIban()
                 << ", " << account.getCarte()[j].getDataScadenza() << ", " << account.getCarte()[j].getSaldo() << "];" << endl;
        }
        indice = i + 1;
    }
}

void Finanza :: stampaTransazioni(Account account, Carte carta) {
    int indice = 1;
    cout << "STAMPA DATI DI TUTTE LE TRANSAZIONI:" << endl;

    for(int i = 0; i < accounts.size(); i++) {
        for(int j = 0; j < account.getCarte().size(); j++) {
            for(int k = 0; k < carta.getTransazioni().size(); k++) {
                cout << "  " << indice << "-> [" << carta.getTransazioni()[k].getData() << ", " << carta.getTransazioni()[k].getImporto()
                     << ", " << carta.getTransazioni()[k].getGiorno() << "];" << endl;
                indice++;
            }
        }
    }
}

void Finanza :: stampaTransazioniAccount(Account account, Carte carta) {
    int indice = 1;

    for(int i = 0; i < accounts.size(); i++) {
        indice += i;
        cout << indice << ". " << accounts[i].getNome() << " " << accounts[i].getCognome() << ":" << endl;

        for(int j = 0; j < account.getCarte().size(); j++) {
            indice += j;
            cout << "  " << indice << "-> " << account.getCarte()[j].getNumeroConto() << ", " << account.getCarte()[j].getIban() << ";" << endl;

            for(int k = 0; k < carta.getTransazioni().size(); k++) {
                indice += k;
                cout << "  " << indice << "-> [" << carta.getTransazioni()[k].getData() << ", " << carta.getTransazioni()[k].getImporto()
                     << ", " << carta.getTransazioni()[k].getGiorno() << "];" << endl;
            }
            indice = j + 1;
        }
        indice = i + 1;
    }
}