#include <gtest/gtest.h>
#include <math/vector3.hpp>
#include <type_traits>

TEST(Vector3, Constructor_ShouldInitializeSuccessfully)
{
    EXPECT_NO_THROW(my::math::Vector3 dummy);
    EXPECT_NO_THROW(my::math::Vector3 dummy(1.0));
    EXPECT_NO_THROW(my::math::Vector3 dummy(1.0, 2.0, 3.0));
    EXPECT_NO_THROW(my::math::Vector3 dummy(my::math::Vector3{1.0, 2.0, 3.0}));
}

TEST(Vector3, PublicAccessors_ShouldReturnCorrectValues)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    EXPECT_EQ(first.x, 1.0);
    EXPECT_EQ(first.y, 2.0);
    EXPECT_EQ(first.z, 3.0);
}

TEST(Vector3, SingleFloatConstructor_ShouldNotImplicitlyConvert)
{
    bool result = std::is_convertible_v<float, my::math::Vector3>;
    EXPECT_FALSE(result);
}

TEST(Vector3, MethodAdd_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0);

    first.add(my::math::Vector3{4.0});
    bool allFives = first.x == 5.0 && first.y == 5.0 && first.z == 5.0;
    EXPECT_TRUE(allFives);

    first.add(my::math::Vector3{-5.0});
    bool allZeros = first.x == 0.0 && first.y == 0.0 && first.z == 0.0;
    EXPECT_TRUE(allZeros);

    first.add(1.0);
    bool allOnes = first.x == 1.0 && first.y == 1.0 && first.z == 1.0;
    EXPECT_TRUE(allOnes);
}

TEST(Vector3, MethodSubtract_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0);

    first.subtract(my::math::Vector3{1.0});
    bool allZeroes = first.x == 0.0 && first.y == 0.0 && first.z == 0.0;
    EXPECT_TRUE(allZeroes);

    first.subtract(my::math::Vector3{-1.0});
    bool allOnes = first.x == 1.0 && first.y == 1.0 && first.z == 1.0;
    EXPECT_TRUE(allOnes);

    first.subtract(1.0);
    allZeroes = first.x == 0.0 && first.y == 0.0 && first.z == 0.0;
    EXPECT_TRUE(allZeroes);
}

TEST(Vector3, MethodScale_ShouldScaleVectorSuccessfully)
{
    my::math::Vector3 first(1.0);
    first.scale(2.0);
    bool allTwos = first.x == 2.0 && first.y == 2.0 && first.z == 2.0;
    EXPECT_TRUE(allTwos);
}

TEST(Vector3, MethodDivide_ShouldDivideVectorSuccessfully)
{
    my::math::Vector3 first(4.0);
    first.divide(2.0);
    bool allTwos = first.x == 2.0 && first.y == 2.0 && first.z == 2.0;
    EXPECT_TRUE(allTwos);
}

TEST(Vector3, MethodDot_ShouldGiveRightScalar)
{
    my::math::Vector3 first(1.0);
    my::math::Vector3 second(2.0);
    EXPECT_EQ(first.dot(second), 6.0);
}

TEST(Vector3, MethodCross_ShouldGiveRightScalar)
{
    my::math::Vector3 first(8.0, 1.0, 4.0);
    my::math::Vector3 second(3.0, 2.0, 1.0);
    my::math::Vector3 result = first.cross(second);
    my::math::Vector3 expected(-7.0, 4.0, 13.0);
    EXPECT_EQ(result, expected);
}

TEST(Vector3, MethodProjectedOnto_ShouldGiveRightProjection)
{
    my::math::Vector3 first(1.0, 3.0, 4.0);
    my::math::Vector3 second(5.0, 2.0, 4.0);

    my::math::Vector3 projection = first.projectedOnto(second);

    EXPECT_NEAR(projection.x, 3.0, 1e-1f);
    EXPECT_NEAR(projection.y, 1.2, 1e-1f);
    EXPECT_NEAR(projection.z, 2.4, 1e-1f);
}

TEST(Vector3, MethodMagnitude_ShouldReturnCorrectMagnitude)
{
    my::math::Vector3 result(6.0, 8.0, 0.0);
    EXPECT_EQ(result.magnitude(), 10.0);
}

TEST(Vector3, MethodNormalize_ShouldNormalizeMutateVectorWithCorrectValues)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    first.normalize();
    EXPECT_NEAR(first.x, 0.2672, 1e-4f);
    EXPECT_NEAR(first.y, 0.5345, 1e-4f);
    EXPECT_NEAR(first.z, 0.8018, 1e-4f);
    EXPECT_EQ(first.magnitude(), 1.0); // should be unit vector after normalization
}

TEST(Vector3, MethodIsNormalized_ShouldReturnTrueWhenVectorIsNormalized)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    first.normalize();
    EXPECT_TRUE(first.isNormalized());
}

TEST(Vector3, MethodNormalized_ShouldReturnCorrectNormalizedVector)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    my::math::Vector3 normalized = first.normalized();
    EXPECT_NEAR(normalized.x, 0.2672, 1e-4f);
    EXPECT_NEAR(normalized.y, 0.5345, 1e-4f);
    EXPECT_NEAR(normalized.z, 0.8018, 1e-4f);
}

TEST(Vector3, AddTwoVectors_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    my::math::Vector3 second(4.0, 3.0, 2.0);
    my::math::Vector3 result = first + second;
    bool allFives = result.x == 5.0 && result.y == 5.0 && result.z == 5.0;
    EXPECT_TRUE(allFives);
}

TEST(Vector3, AddScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0);
    my::math::Vector3 result = first + 1.0;
    bool allTwos = result.x == 2.0 && result.y == 2.0 && result.z == 2.0;
    EXPECT_TRUE(allTwos);
}

TEST(Vector3, AddOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0);
    first += 1.0;
    bool allTwos = first.x == 2.0 && first.y == 2.0 && first.z == 2.0;
    EXPECT_TRUE(allTwos);
}

TEST(Vector3, SubtractScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    my::math::Vector3 result = first - 1.0;
    bool allTwos = result.x == 2.0 && result.y == 2.0 && result.z == 2.0;
    EXPECT_TRUE(allTwos);
}

TEST(Vector3, SubtractOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    first -= 1.0;
    bool allTwos = first.x == 2.0 && first.y == 2.0 && first.z == 2.0;
    EXPECT_TRUE(allTwos);
}

TEST(Vector3, MultiplyScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    my::math::Vector3 result = first * 2.0;
    bool allSix = result.x == 6.0 && result.y == 6.0 && result.z == 6.0;
    EXPECT_TRUE(allSix);
}

TEST(Vector3, MultiplyOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    first *= 2.0;
    bool allSix = first.x == 6.0 && first.y == 6.0 && first.z == 6.0;
    EXPECT_TRUE(allSix);
}

TEST(Vector3, DivideScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(6.0);
    my::math::Vector3 result = first / 2.0;
    bool allThrees = result.x == 3.0 && result.y == 3.0 && result.z == 3.0;
    EXPECT_TRUE(allThrees);
}

TEST(Vector3, DivideOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(6.0);
    first /= 2.0;
    bool allThrees = first.x == 3.0 && first.y == 3.0 && first.z == 3.0;
    EXPECT_TRUE(allThrees);
}

TEST(Vector3, AddOneVectorToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    my::math::Vector3 second(4.0, 3.0, 2.0);
    first += second;
    bool allFives = first.x == 5.0 && first.y == 5.0 && first.z == 5.0;
    EXPECT_TRUE(allFives);
}

TEST(Vector3, AddMultipleVectorsToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    my::math::Vector3 second(4.0, 3.0, 2.0);
    first += second + second;
    EXPECT_EQ(first.x, 9.0);
    EXPECT_EQ(first.y, 8.0);
    EXPECT_EQ(first.z, 7.0);
}

TEST(Vector3, SubtractTwoVectors_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0);
    my::math::Vector3 second(1.0);
    my::math::Vector3 result = first - second;
    bool allOnes = result.x == 1.0 && result.y == 1.0 && result.z == 1.0;
    EXPECT_TRUE(allOnes);
}

TEST(Vector3, SubtractOneVectorToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0);
    my::math::Vector3 second(1.0);
    first -= second;
    bool allOnes = first.x == 1.0 && first.y == 1.0 && first.z == 1.0;
    EXPECT_TRUE(allOnes);
}

TEST(Vector3, SubtractMultipleVectorsToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0);
    my::math::Vector3 second(1.0);
    first -= second - second;
    bool allTwos = first.x == 2.0 && first.y == 2.0 && first.z == 2.0;
    EXPECT_TRUE(allTwos);
}