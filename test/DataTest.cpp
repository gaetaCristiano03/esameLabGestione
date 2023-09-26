#include "lib/googletest/include/gtest/gtest.h"
#include "../Data.h"

TEST(Data, controlloCostruttore) {
    EXPECT_THROW({
        Data d(45, 12, 2003); // Questo dovrebbe lanciare un'eccezione
    }, invalid_argument);
}
