#include <iostream>
#include "Finanza.h"
#include "Account.h"
#include "Carte.h"
#include "Transazione.h"
#include "Data.h"

using namespace std;

Account controlloEsistenzaAccount(Finanza finanza);
Carte controlloEsistenzaCarte(Account account);
int stampaMenu();
void stampaMenuCarte(const Finanza &finanza, Account &account);
void stampaMenuTransazioni(Finanza finanza, Account account, Carte &carta);

int numeroCon, sal, impor, condizionePrelDep, cod;
string no, cog, em, ib, cau;
unsigned long int numeroTel, et;
Data da(45, 1, 2002);

int main() {
    int scelta;
    Finanza finanza;
    Account account;
    Carte carta;
    Transazione transazione(da, 1, true, 1, "a");

    do {
        scelta = stampaMenu();

        switch(scelta) {
            case 0:
                return 0;

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

        if(!controllo)
            cout << "Account non trovato, riprovare." << endl;
    } while(!controllo);

    return acc;
}

Carte controlloEsistenzaCarte(Account account) {
    bool control;
    Carte carta;

    do {
        account.inserisciDatiCarta(numeroCon, sal, ib);
        carta = Carte(numeroCon, sal, ib);
        control = account.cercaCarta(carta);

        if(!control)
            cout << "Account non trovato, riprovare." << endl;
    } while(!control);

    return carta;

}

int stampaMenu() {
    int scelta;

    cout << " _____           _   _                           " << endl;
    cout << "|  __ \\         | | (_)                         " << endl;
    cout << "| |  \\/ ___  ___| |_ _  ___  _ __   ___         " << endl;
    cout << "| | __ / _ \\/ __| __| |/ _ \\| '_ \\ / _ \\     " << endl;
    cout << "| |_\\ \\  __/\\__ \\ |_| | (_) | | | |  __/     " << endl;
    cout << " \\____/\\___||___/\\__|_|\\___/|_| |_|\\___|     " << endl;

    cout << " __ _                       _            _                  " << endl;
    cout << "/ _(_)                     (_)          (_)         _       " << endl;
    cout << "| |_ _ _ __   __ _ _ __  _____  __ _ _ __ _  __ _  (_)      " << endl;
    cout << "|  _| | '_ \\ / _` | '_ \\|_  / |/ _` | '__| |/ _` |        " << endl;
    cout << "| | | | | | | (_| | | | |/ /| | (_| | |  | | (_| |  _       " << endl;
    cout << "|_| |_|_| |_|\\__,_|_| |_/___|_|\\__,_|_|  |_|\\__,_| (_)   " << endl;

    cout << "0. Esci dal programma;"   << endl;
    cout << "1. Gestione utenti;"      << endl;
    cout << "2. Gestione conti/carte;" << endl;
    cout << "3. Gestione transazioni;"   << endl;
    cout << "4. Visualizzazione dati;" << endl;
    cout << "5. Ripristina file."      << endl;

    cout << "Inserisci la tua scelta ->  ";
    cin >> scelta;
    cout << endl;

    while (scelta < 0 || scelta > 5) {
        cout << "Inserimento I/O errato, riprovare." << endl;
        cout << "Scegli una opzione -> ";
        cin >> scelta;
    }
    cout << endl;

    return scelta;
}

void stampaMenuCarte(const Finanza &finanza, Account &account) {
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
    int scelta;
    cout << "GESTIONE TRANSAZIONI PRELIEVO/DEPOSITO:" << endl;
    cout << " 1. Inserisci nuova transazioni;" << endl;
    cout << " 2. Modifica transazione;" << endl;
    cout << " 3. Elimina transazione;" << endl;

    cout << "Scegli una delle seguenti opzioni -> ";
    cin >> scelta;
    cout << endl;

    while (scelta < 1 || scelta > 3) {
        cout << "Inserimento I/O errato, riprovare." << endl;
        cout << "Scegli una opzione -> ";
        cin >> scelta;
    }
    cout << endl;

    if(scelta == 1) {
        cout << "INSERIMENTO TRANSAZIONI PRELIEVO/DEPOSITO:" << endl;
        cout << "Inserisci alcuni dati dell'utente per trovarlo:" << endl;
        Account acc = controlloEsistenzaAccount(finanza);
        cout << endl << "Ora inserisci i dati della carta: " << endl;
        Carte car = controlloEsistenzaCarte(account);

        int sceltaOperazione;
        cout << endl << "Perfetto! Ora scegli la tua operazione:" << endl;
        cout << "1. Operazione prelievo;" << endl;
        cout << "2. Operazione deposito." << endl;
        cin >> sceltaOperazione;

        finanza.eseguiOperazione(account, carta, acc, car, sceltaOperazione);
    }

    else if(scelta  == 2) {
        cout << "MODIFICA TRANSAZIONI PRELIEVO/DEPOSITO:" << endl;
        cout << "Inserisci alcuni dati per trovare la transazione:" << endl;
        cout << "1. Numero di telefono dell'utente -> ";
        cin >> numeroTel;
        cout << "2. Codice iban della carta -> ";
        cin >> ib;
        cout << "3. Era un prelievo(0) o un deposito(1)?";
        cin >> condizionePrelDep;

        if(condizionePrelDep == 0)
            finanza.modificaOperazione(account, carta, numeroTel, ib, true);
        else
            finanza.modificaOperazione(account, carta, numeroTel, ib, false);
    }

    else {
        Transazione tran(da, 1, true, 1, "a");
        cout << "ELIMINAZIONE TRANSAZIONI PRELIEVO/DEPOSITO:" << endl;
        cout << "Inserisci alcuni dati dell'utente per trovarlo:" << endl;
        Account acc = controlloEsistenzaAccount(finanza);
        cout << endl << "Ora inserisci i dati della carta: " << endl;
        Carte car = controlloEsistenzaCarte(account);
        cout << endl << "Ora inserisci i dati della transazione: " << endl;
        carta.inserisciDatiTransazione(da, impor, cod, cau);
        cout << "4. Era un prelievo(0) o un deposito(1)?";
        cin >> condizionePrelDep;

        if(condizionePrelDep == 0)
            tran = Transazione(da, impor, true, cod, cau);
        else
            tran = Transazione(da, impor, false, cod, cau);

        finanza.eliminaOperazione(account, carta, acc, car, tran);
    }

}