#include <iostream>
#include "Account.h"

using namespace std;

Account :: Account() {};

Account :: Account(const string &nome, const string &cognome, const string &email, const unsigned long int &numeroTelefono, const unsigned long int &eta) :
        nome(nome), cognome(cognome), email(email), numeroTelefono(numeroTelefono), eta(eta){};