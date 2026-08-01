#include <gtest/gtest.h>
#include <math/vector3.hpp>

TEST(Vector3, Constructor_ShouldInitializeSuccessfully)
{
    EXPECT_NO_THROW(my::math::Vector3 dummy(1.0f, 2.0f, 3.0f));
    EXPECT_NO_THROW(my::math::Vector3 dummy(1.0f));
}

TEST(Vector3, PublicAccessors_ShouldReturnCorrectValues)
{
    my::math::Vector3 first(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(first.x, 1.0f);
    EXPECT_EQ(first.y, 2.0f);
    EXPECT_EQ(first.z, 3.0f);
}

TEST(Vector3, MethodAdd_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0f, 1.0f, 1.0f);

    first.add(my::math::Vector3{4.0f});
    bool allFives = first.x == 5.0f && first.y == 5.0f && first.z == 5.0f;
    EXPECT_TRUE(allFives);

    first.add(my::math::Vector3{-5.0f});
    bool allZeros = first.x == 0.0f && first.y == 0.0f && first.z == 0.0f;
    EXPECT_TRUE(allZeros);
}

TEST(Vector3, MethodSubtract_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0f, 1.0f, 1.0f);

    first.subtract(my::math::Vector3{1.0f});
    bool allZeroes = first.x == 0.0f && first.y == 0.0f && first.z == 0.0f;
    EXPECT_TRUE(allZeroes);

    first.subtract(my::math::Vector3{-1.0f});
    bool allOnes = first.x == 1.0f && first.y == 1.0f && first.z == 1.0f;
    EXPECT_TRUE(allOnes);
}

TEST(Vector3, AddTwoVectors_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0f, 2.0f, 3.0f);
    my::math::Vector3 second(4.0f, 3.0f, 2.0f);
    my::math::Vector3 result = first + second;
    bool allFives = result.x == 5.0f && result.y == 5.0f && result.z == 5.0f;
    EXPECT_TRUE(allFives);
}

TEST(Vector3, AddOneVectorToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0f, 2.0f, 3.0f);
    my::math::Vector3 second(4.0f, 3.0f, 2.0f);
    first += second;
    bool allFives = first.x == 5.0f && first.y == 5.0f && first.z == 5.0f;
    EXPECT_TRUE(allFives);
}

TEST(Vector3, AddMultipleVectorsToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0f, 2.0f, 3.0f);
    my::math::Vector3 second(4.0f, 3.0f, 2.0f);
    first += second + second;
    EXPECT_EQ(first.x, 9.0f);
    EXPECT_EQ(first.y, 8.0f);
    EXPECT_EQ(first.z, 7.0f);
}

TEST(Vector3, SubtractTwoVectors_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0f, 2.0f, 2.0f);
    my::math::Vector3 second(1.0f, 1.0f, 1.0f);
    my::math::Vector3 result = first - second;
    bool allOnes = result.x == 1.0f && result.y == 1.0f && result.z == 1.0f;
    EXPECT_TRUE(allOnes);
}

TEST(Vector3, SubtractOneVectorToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0f, 2.0f, 2.0f);
    my::math::Vector3 second(1.0f, 1.0f, 1.0f);
    first -= second;
    bool allOnes = first.x == 1.0f && first.y == 1.0f && first.z == 1.0f;
    EXPECT_TRUE(allOnes);
}

TEST(Vector3, SubtractMultipleVectorsToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0f, 2.0f, 2.0f);
    my::math::Vector3 second(1.0f, 1.0f, 1.0f);
    first -= second - second;
    bool allTwos = first.x == 2.0f && first.y == 2.0f && first.z == 2.0f;
    EXPECT_TRUE(allTwos);
}