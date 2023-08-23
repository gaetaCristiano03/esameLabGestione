#include "lib/googletest/include/gtest/gtest.h"
#include "../Finanza.h"

TEST(Finanza, ricercaAccountFalse) {
    Finanza finanza;
    Account account("Gaetano", "Cristiano", "gae@", 366, 19);

    bool control = finanza.cercaAccount(account);
    ASSERT_FALSE(control);
}

TEST(Finanza, ricercaAccountTrue) {
    Finanza finanza;
    Account account("Gaetano", "Cristiano", "gae@", 366, 19);

    finanza.setAccount(account);
    bool control = finanza.cercaAccount(account);
    ASSERT_TRUE(control);
}