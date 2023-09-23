#include "lib/googletest/include/gtest/gtest.h"
#include "../Data.h"

TEST(Data, costruttoreParametrizzato) {
    Data d(3, 45, 2000);
    ASSERT_EQ(d.getGiorno(), 3);
}
