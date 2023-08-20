#include <iostream>
#include <windows.h>
#include "Finanza.h"
#include "Account.h"
#include "Carte.h"
#include "Transazione.h"

using namespace std;

Account controlloEsistenzaAccount(Finanza finanza);
Carte controlloEsistenzaCarte(Account account);
int stampaMenu();
void stampaMenuCarte(Finanza finanza, Account &account);
void stampaMenuTransazioni(Finanza finanza, Account account, Carte &carta);

int sl = 20, numeroCon, dataScad, sal;
string no, cog, em, ib;
unsigned long int numeroTel, et;

int main() {
    int scelta;
    Finanza finanza;
    Account account;
    Carte carta;
    Transazione transazione;

    do {
        scelta = stampaMenu();

        switch(scelta) {
            case 1:
                finanza.stampaMenuAccount();
                break;

            case 2:
                stampaMenuCarte(finanza, account);
                break;

            case 3:
                stampaMenuTransazioni(finanza, account, carta);
                break;

            case 4:
                finanza.stampaMenuVisualizzazioni(account, carta);
                break;

            case 5:
                ofstream file("Salvataggio_dati.txt", ios::trunc);
                file.close();
                cout << "File ripristinato!" << endl;
                break;
        }

    } while(scelta >= 0 && scelta <= 5);

    return 0;
}

Account controlloEsistenzaAccount(Finanza finanza) {
    bool controllo;
    Account acc;

    do {
        finanza.inserisciDatiAccount(no, cog, em, numeroTel, et);
        acc = Account(no, cog, em, numeroTel, et);
        controllo = finanza.cercaAccount(acc);
    } while(controllo == false);

    return acc;
}

Carte controlloEsistenzaCarte(Account account) {
    bool control;
    Carte carta;

    do {
        account.inserisciDatiCarta(numeroCon, dataScad, sal, ib);
        carta = Carte(numeroCon, dataScad, sal, ib);
        control = account.cercaCarta(carta);
    } while(control == false);

    return carta;

}

int stampaMenu() {
    int scelta;

    cout << " _____           _   _                           " << endl; Sleep(sl);
    cout << "|  __ \\         | | (_)                         " << endl; Sleep(sl);
    cout << "| |  \\/ ___  ___| |_ _  ___  _ __   ___         " << endl; Sleep(sl);
    cout << "| | __ / _ \\/ __| __| |/ _ \\| '_ \\ / _ \\     " << endl; Sleep(sl);
    cout << "| |_\\ \\  __/\\__ \\ |_| | (_) | | | |  __/     " << endl; Sleep(sl);
    cout << "\\____/\\___||___/\\__|_|\\___/|_| |_|\\___|     " << endl; Sleep(sl);

    cout << " __ _                       _            _                  " << endl; Sleep(sl);
    cout << "/ _(_)                     (_)          (_)         _       " << endl; Sleep(sl);
    cout << "| |_ _ _ __   __ _ _ __  _____  __ _ _ __ _  __ _  (_)      " << endl; Sleep(sl);
    cout << "|  _| | '_ \\ / _` | '_ \\|_  / |/ _` | '__| |/ _` |        " << endl; Sleep(sl);
    cout << "| | | | | | | (_| | | | |/ /| | (_| | |  | | (_| |  _       " << endl; Sleep(sl);
    cout << "|_| |_|_| |_|\\__,_|_| |_/___|_|\\__,_|_|  |_|\\__,_| (_)   " << endl; Sleep(sl);

    cout << "0. Esci dal programma;"   << endl; Sleep(sl);
    cout << "1. Gestione utenti;"      << endl; Sleep(sl);
    cout << "2. Gestione conti/carte;" << endl; Sleep(sl);
    cout << "3. Esegui transazioni;"   << endl; Sleep(sl);
    cout << "4. Visualizzazione dati;" << endl; Sleep(sl);
    cout << "5. Ripristina file."      << endl; Sleep(sl);

    cout << "Inserisci la tua scelta ->  "; Sleep(sl);
    cin >> scelta;
    cout << endl;

    return scelta;
}

void stampaMenuCarte(Finanza finanza, Account &account) {
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

    if(scelta == 1) {
        Account acc = controlloEsistenzaAccount(finanza);
        account.creazioneCarta(acc);
    }

    else if(scelta == 2) {
        cout << "AREA MODIFICA CARTA:" << endl;
        cout << "Inserisci i dati dell'utente a cui e' intestata la carta:" << endl;
        Account acc = controlloEsistenzaAccount(finanza);
        account.modificaCarta();
    }

    else if(scelta == 3) {
        cout << "AREA ELIMINAZIONE CARTA:" << endl;
        cout << "Inserisci i dati dell'utente a cui e' intestata la carta:" << endl;
        Account acc = controlloEsistenzaAccount(finanza);
        account.eliminaCarta(acc);
    }
}

void stampaMenuTransazioni(Finanza finanza, Account account, Carte &carta) {
    cout << "TRANSAZIONI PRELIEVO / DEPOSITO:" << endl;
    cout << "Inserisci alcuni dati dell'utente per trovarlo:" << endl;
    Account acc = controlloEsistenzaAccount(finanza);

    cout << endl << "Ora inserisci i dati della carta: " << endl;
    Carte car = controlloEsistenzaCarte(account);

    int scelta;
    cout << endl << "Perfetto! Ora scegli la tua operazione:" << endl;
    cout << "1. Operazione prelievo;" << endl;
    cout << "2. Operazione deposito." << endl;
    cin >> scelta;

    finanza.eseguiOperazione(account, carta, acc, car, scelta);
}