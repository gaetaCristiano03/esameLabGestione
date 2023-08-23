#include "lib/googletest/include/gtest/gtest.h"
#include "../Transazione.h"

TEST(Transazione, costruttoreDefault) {
    Data data(10, 12, 2003);
    Transazione transazione(data, 100, true, 235232, "Tasse");
    ASSERT_EQ(100, transazione.getImporto());
    ASSERT_TRUE(transazione.getBool());
}