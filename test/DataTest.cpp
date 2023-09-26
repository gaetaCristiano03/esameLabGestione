#include "lib/googletest/include/gtest/gtest.h"
#include "../Data.h"

TEST(Data, controlloCostruttore) {
    EXPECT_THROW({
        Data d(45, 12, 2003); //Dati non validi
    }, invalid_argument);
}
