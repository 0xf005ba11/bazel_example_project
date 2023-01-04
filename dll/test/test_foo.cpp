#include <gtest/gtest.h>

#include "dll/dll.h"

TEST(FooTest, Expected)
{
    EXPECT_EQ(Foo(), true);
}