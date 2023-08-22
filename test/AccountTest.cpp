#include "lib/googletest/include/gtest/gtest.h"
#include "../Account.h"

TEST(Account, defaultCosnstructor) {
    Account a;
    a = Account("", "", "", 0, 0);
    ASSERT_EQ(0, a.getNumeroTelefono());
}
