#include <iostream>
#include <windows.h>
#include "Finanza.h"
#include "Account.h"
#include "Carte.h"
#include "Transazione.h"

using namespace std;

int stampaMenu();

int sl = 100;

int main() {
    int scelta = 0;

    Finanza finanza;
    Account account;
    //Carte carta;
    //Transazione transazione;


    do {
        scelta = stampaMenu();

        switch(scelta) {
            case 1:
                finanza.stampaMenuAccount();
                break;
            case 2:
                account.stampaMenuCarte();
                break;
            case 3:
                break;
            case 4:
                break;
        }


    } while(scelta >= 0 && scelta <= 4);

    return 0;
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
    cout << "3. Visualizzazione dati;" << endl; Sleep(sl);
    cout << "4. Ripristina file."      << endl; Sleep(sl);

    cout << "Inserisci la tua scelta ->  "; Sleep(sl);
    cin >> scelta;
    cout << endl;

    return scelta;
}
