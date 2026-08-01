#include <gtest/gtest.h>
#include <math/vector3.hpp>

TEST(Vector3, ConstructorShouldInitializeSuccessfully)
{
    EXPECT_NO_THROW(my::math::Vector3 dummy(1.0f, 2.0f, 3.0f));
}

TEST(Vector3, AccessorShouldReturnCorrectValues)
{
    my::math::Vector3 dummy(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(dummy.x, 1.0f);
    EXPECT_EQ(dummy.y, 2.0f);
    EXPECT_EQ(dummy.z, 3.0f);
}