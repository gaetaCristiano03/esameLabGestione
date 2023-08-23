#include <iostream>
#include "Account.h"

using namespace std;

int numeroConto, dataScadenza, saldo;
string iban;
bool controlloEs = false;

Account :: Account() {};

Account :: Account(const string &nome, const string &cognome, const string &email, const unsigned long int &numeroTelefono, const unsigned long int &eta) :
        nome(nome), cognome(cognome), email(email), numeroTelefono(numeroTelefono), eta(eta){};

void Account :: controlloDatiNelFileCarte(Account account) {
    ifstream file("Salvataggio_dati.txt");

    vector<string> lines;
    string line;

    if (file.is_open()) {

        while (getline(file, line)) {
            if (line != "Conto di " + account.getNome() + " " + account.getCognome() + ":") {
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
}

void Account :: inserisciDatiCarta(int &numeroConto, int &saldo, string &iban) {
    cout << "INSERIMENTO DATI CARTA:" << endl;
    cout << " 1. Numero del conto -> ";
    cin >> numeroConto;
    cout << "2. Saldo -> ";
    cin >> saldo;
    cout << "3. Iban -> ";
    cin >> iban;
}

bool Account :: cercaCarta(Carte carta) {
    for(int i = 0; i < carte.size(); i++) {
        if(carte[i].getNumeroConto() == carta.getNumeroConto()) {
            if(carte[i].getIban() == carta.getIban()) {
                if(carte[i].getSaldo() == carta.getSaldo()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Account :: creazioneCarta(Account account) {

    inserisciDatiCarta(numeroConto, saldo, iban);
    Carte carta(numeroConto, saldo, iban);
    controlloEs = cercaCarta(carta);

    for(int i = 0; i < carte.size(); i++) {
        if(carte[i].getIban() == carta.getIban())
            controlloEs = true;
    }

    if(controlloEs == false) {
        carte.push_back(carta);
        cout << "Creazione carta completata!" << endl;

        ofstream file("Salvataggio_dati.txt", ios::app);

        if (file.is_open()) {
            string lineNameUser = "Conto di " + account.getNome() + " " + account.getCognome() + ":";
            file << lineNameUser << endl;
            string lineCont = " Numero carta -> " + to_string(carta.getNumeroConto()) + ", Salario -> " + to_string(carta.getSaldo())
                              + ", Iban -> " + carta.getIban() + ";";
            file << lineCont << endl << endl;
        } else cout << "Impossibile aprire il file." << endl;

        file.close();
    }
    else
        cout << "Carta gia' esistente, inserire dati diversi." << endl;
}

void Account :: modificaCarta() {
    Carte cartaPre;
    inserisciDatiCarta(numeroConto, saldo, iban);
    cartaPre = Carte(numeroConto, saldo, iban);
    controlloEs = cercaCarta(cartaPre);

    if(controlloEs == true) {
        cout << "Inserisci i dati della nuova carta:" << endl;
        inserisciDatiCarta(numeroConto, saldo, iban);
        Carte cartaPost(numeroConto, saldo, iban);

        for (int i = 0; i < carte.size(); i++) {
            if (carte[i].getIban() == cartaPre.getIban()) {
                carte[i] = cartaPost;

                ifstream file("Salvataggio_dati.txt");

                if (file.is_open()) {
                    vector<string> lines;
                    string line;

                    while (getline(file, line)) {
                        if (line == " Numero carta -> " + to_string(cartaPre.getNumeroConto()) + ", Salario -> " + to_string(cartaPre.getSaldo())
                                    + ", Iban -> " + cartaPre.getIban() + ";") {

                            line = " Numero carta -> " + to_string(cartaPost.getNumeroConto()) + ", Salario -> " + to_string(cartaPost.getSaldo())
                                   + ", Iban -> " + cartaPost.getIban() + ";";
                        }
                        lines.push_back(line);
                    }

                    ofstream file("Salvataggio_dati.txt");

                    if (file.is_open()) {
                        for (const auto &line: lines) {
                            file << line << endl;
                        }
                        file.close();

                        cout << "Modifica completata e le righe sono state modificate nel file." << std::endl;
                    }
                } else cout << "Errore nell'apertura del file." << std::endl;

                file.close();
                break;
            }
        }
    }
    else cout << "Carta non trovata, riprovare." << endl;
}

void Account :: eliminaCarta(Account account) {
    Carte carta;
    cout << "ELIMINAZIONE CARTA:" << endl;
    cout << "Inserisci i dati della carta:" << endl;

    inserisciDatiCarta(numeroConto, saldo, iban);
    carta = Carte(numeroConto, saldo, iban);
    controlloEs = cercaCarta(carta);

    if(controlloEs == true) {
        for (int i = 0; i < carte.size(); i++) {
            if (carte[i].getIban() == carta.getIban()) {
                auto k = i + carte.begin();
                carte.erase(k);

                ifstream file("Salvataggio_dati.txt");

                vector<string> lines;
                string line;

                if (file.is_open()) {

                    while (getline(file, line)) {
                        if (line != " Numero carta -> " + to_string(carta.getNumeroConto()) + ", Salario -> " + to_string(carta.getSaldo())
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
                    }
                    controlloDatiNelFileCarte(account);
                }
                else cout << "Errore nell'apertura del file." << endl;
            }
        }
    }
    else
        cout << "Carta non trovata, riprovare." << endl;
}

void Account :: cambiaSalario(int indice, const Carte carta) {
    carte[indice] = carta;
}