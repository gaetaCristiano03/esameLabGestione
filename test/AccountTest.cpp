#include "lib/googletest/include/gtest/gtest.h"
#include "../Account.h"

TEST(Account, costruttoreDefault) {
    Account a;
    a = Account("", "", "", 0, 0);
    ASSERT_EQ("", a.getNome());
    ASSERT_EQ("", a.getCognome());
    ASSERT_EQ("", a.getEmail());
    ASSERT_EQ(0, a.getNumeroTelefono());
    ASSERT_EQ(0, a.getEta());
}

TEST(Account, ricercaCartaFalse) {
    Account account;
    Carte carta(4023, 1500, "IT09");

    bool control = account.cercaCarta(carta);
    ASSERT_FALSE(control);
}

TEST(Account, ricercaCartaTrue) {
    Account account;
    Carte carta(4023, 1500, "IT09");

    account.setCarte(carta);

    bool control = account.cercaCarta(carta);
    ASSERT_TRUE(control);
}