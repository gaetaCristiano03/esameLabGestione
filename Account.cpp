#include <iostream>
#include "Account.h"

using namespace std;

int numeroConto, dataScadenza, saldo;
string iban;
bool controlloEs = false;

Account :: Account() {};

Account :: Account(const string &nome, const string &cognome, const string &email, const unsigned long int &numeroTelefono, const unsigned long int &eta) :
        nome(nome), cognome(cognome), email(email), numeroTelefono(numeroTelefono), eta(eta){};

void Account :: inserisciDatiCarta(int &numeroConto, int &dataScadenza, int &saldo, string &iban) {
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

bool Account :: cercaCarta(Carte carta) {
    for(int i = 0; i < carte.size(); i++) {
        if(carta.getIban() == carte[i].getIban())
            return true;
    }
    return false;
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

void Account :: modificaCarta() {
    Carte cartaPre;

    do {
        inserisciDatiCarta(numeroConto, dataScadenza, saldo, iban);
        cartaPre = Carte(numeroConto, dataScadenza, saldo, iban);
        controlloEs = cercaCarta(cartaPre);
    } while(controlloEs == false);

    cout << "Inserisci i dati della nuova carta:" << endl;
    inserisciDatiCarta(numeroConto, dataScadenza, saldo, iban);
    Carte cartaPost(numeroConto, dataScadenza, saldo, iban);

    for(int i = 0; i < carte.size(); i++) {
        if(carte[i].getIban() == cartaPre.getIban()) {
            carte[i] = cartaPost;

            ifstream file("Salvataggio_dati.txt");

            if (file.is_open()) {
                vector<string> lines;
                string line;

                while (getline(file, line)) {
                    if (line == " Numero carta -> " + to_string(cartaPre.getNumeroConto()) + ", Data scadenza -> " +
                                to_string(cartaPre.getDataScadenza()) + ", Salario -> " + to_string(cartaPre.getSaldo())
                                + ", Iban -> " + cartaPre.getIban() + ";") {

                        line = " Numero carta -> " + to_string(cartaPost.getNumeroConto()) + ", Data scadenza -> " +
                               to_string(cartaPost.getDataScadenza()) + ", Salario -> " + to_string(cartaPost.getSaldo())
                               + ", Iban -> " + cartaPost.getIban() + ";";
                    }
                    lines.push_back(line);
                }

                ofstream file("Salvataggio_dati.txt");

                if (file.is_open()) {
                    for (const auto& line : lines) {
                        file << line << endl;
                    }
                    file.close();

                    cout << "Modifica completata e le righe sono state modificate nel file." << std::endl;
                }
            }
            else cout << "Errore nell'apertura del file." << std::endl;

            file.close();
            break;
        }
    }
    controlloEs = false;
}

void Account :: eliminaCarta() {
    Carte carta;
    cout << "ELIMINAZIONE CARTA:" << endl;
    cout << "Inserisci i dati della carta:" << endl;

    do {
        inserisciDatiCarta(numeroConto, dataScadenza, saldo, iban);
        carta = Carte(numeroConto, dataScadenza, saldo, iban);
        controlloEs = cercaCarta(carta);
    } while(controlloEs == false);

    for(int i = 0; i < carte.size(); i++) {
        if(carte[i].getIban() == carta.getIban()) {
            auto k = i + carte.begin();
            carte.erase(k);

            ifstream file("Salvataggio_dati.txt");

            vector<string> lines;
            string line;

            if (file.is_open()) {

                while (getline(file, line)) {
                    if (line != " Numero carta -> " + to_string(carta.getNumeroConto()) + ", Data scadenza -> " +
                                to_string(carta.getDataScadenza()) + ", Salario -> " + to_string(carta.getSaldo())
                                + ", Iban -> " + carta.getIban() + ";") {
                        lines.push_back(line);
                    }
                }
                file.close();

                ofstream outFile("Salvataggio_dati.txt");

                if (outFile.is_open()) {
                    for (const auto &line: lines) {
                        outFile << line << endl;
                    }
                    outFile.close();

                    cout << "Eliminazione completata e le righe sono state eliminate dal file." << endl;
                }
            }
            else cout << "Errore nell'apertura del file." << endl;
        }
    }
    controlloEs = false;
}

void Account :: setSaldo(int scelta, int indice, int importo) {
    int n;
    if(scelta == 1)
        n = carte[indice].getSaldo() - importo;
    else
        n = carte[indice].getSaldo() + importo;
    carte[indice].setSal(n);
}