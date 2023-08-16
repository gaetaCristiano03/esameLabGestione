#include <iostream>
#include "Finanza.h"

Finanza :: Finanza() {};

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
