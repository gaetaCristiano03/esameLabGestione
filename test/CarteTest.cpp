#include "lib/googletest/include/gtest/gtest.h"
#include "../Carte.h"

TEST(Carte, costruttoreDefault) {
    Carte carta(4023, 1500, "IT09");
    ASSERT_EQ(4023, carta.getNumeroConto());
    ASSERT_EQ(1500, carta.getSaldo());
    ASSERT_EQ("IT09", carta.getIban());
}

TEST(Carte, cercaTransazioneFalse) {
    Carte carta;
    Data data(10, 12, 2003);
    Transazione transazione(data, 200, true, 389412, "Ottimo");

    bool control = carta.cercaTransazione(transazione);
    ASSERT_FALSE(control);
}

TEST(Carte, cercaTranszioneTrue) {
    Carte carta;
    Data data(10, 12, 2003);
    Transazione transazione(data, 200, true, 389412, "Debito");

    carta.setTransazioni(transazione);
    bool control = carta.cercaTransazione(transazione);
    ASSERT_TRUE(control);
}

TEST(Carte, sostituzioneTransazione) {
    Carte carta;
    Data data1(10, 12, 2003);
    Data data2(01, 8, 2004);
    Data data3(22, 10, 2005);

    Transazione transazione1(data1, 100, false, 2481123, "Macchina");
    Transazione transazione2(data2, 900, true, 3204598, "Tasse");
    Transazione transazione3(data3, 100, true, 9438023, "Azienda");

    carta.setTransazioni(transazione1);
    carta.setTransazioni(transazione2);
    carta.setTransazioni(transazione3);

    Transazione transazione4(data2, 8000, true, 6432113, "Ristorante");

    carta.sostituisciTransazione(1, transazione4);
    ASSERT_EQ(8000, carta.getTransazioni()[1].getImporto());
}