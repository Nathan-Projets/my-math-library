#include <gtest/gtest.h>

#include <type_traits>

#include <math/double.hpp>
#include <math/vector3.hpp>

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
    EXPECT_TRUE(my::math::almostEqual(first.x, 1.0));
    EXPECT_TRUE(my::math::almostEqual(first.y, 2.0));
    EXPECT_TRUE(my::math::almostEqual(first.z, 3.0));
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
    EXPECT_TRUE(first.almostEquals(my::math::Vector3{5.0}));

    first.add(my::math::Vector3{-5.0});
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(0.0)));

    first.add(1.0);
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(1.0)));
}

TEST(Vector3, MethodSubtract_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0);

    first.subtract(my::math::Vector3{1.0});
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(0.0)));

    first.subtract(my::math::Vector3{-1.0});
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(1.0)));

    first.subtract(1.0);
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(0.0)));
}

TEST(Vector3, MethodScale_ShouldScaleVectorSuccessfully)
{
    my::math::Vector3 first(1.0);
    first.scale(2.0);
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(2.0)));
}

TEST(Vector3, MethodDivide_ShouldDivideVectorSuccessfully)
{
    my::math::Vector3 first(4.0);
    first.divide(2.0);
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(2.0)));
}

TEST(Vector3, MethodDot_ShouldGiveRightScalar)
{
    my::math::Vector3 first(1.0);
    my::math::Vector3 second(2.0);
    EXPECT_TRUE(my::math::almostEqual(first.dot(second), 6.0));
}

TEST(Vector3, MethodCross_ShouldGiveRightScalar)
{
    my::math::Vector3 first(8.0, 1.0, 4.0);
    my::math::Vector3 second(3.0, 2.0, 1.0);
    my::math::Vector3 result = first.cross(second);
    my::math::Vector3 expected(-7.0, 4.0, 13.0);
    EXPECT_EQ(result, expected);
}

TEST(Vector3, MethodAngleDegrees_ShouldReturnCorrectAngleBetweenTwoVectorsInDegrees)
{
    my::math::Vector3 first(2.0, 7.0, 4.0);
    my::math::Vector3 second(6.0, 3.0, 2.0);

    double angle = first.angleDegrees(second);

    EXPECT_NEAR(angle, 45.1609, 1e-4f);
}

TEST(Vector3, MethodAngleRadians_ShouldReturnCorrectAngleBetweenTwoVectorsInRadians)
{
    my::math::Vector3 first(2.0, 7.0, 4.0);
    my::math::Vector3 second(6.0, 3.0, 2.0);

    double angle = first.angleRadians(second);

    EXPECT_NEAR(angle, 0.7882, 1e-4f);
}

TEST(Vector3, MethodDistance_ShouldReturnCorrectDistanceBetweenTwoVectors)
{
    my::math::Vector3 first(2.0, 7.0, 4.0);
    my::math::Vector3 second(6.0, 3.0, 2.0);

    double distance = first.distance(second);

    EXPECT_TRUE(my::math::almostEqual(distance, 6.0));
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
    EXPECT_TRUE(my::math::almostEqual(result.magnitude(), 10.0));
}

TEST(Vector3, MethodNormalize_ShouldNormalizeMutateVectorWithCorrectValues)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    first.normalize();
    EXPECT_NEAR(first.x, 0.2672, 1e-4f);
    EXPECT_NEAR(first.y, 0.5345, 1e-4f);
    EXPECT_NEAR(first.z, 0.8018, 1e-4f);
    EXPECT_TRUE(my::math::almostEqual(first.magnitude(), 1.0)); // should be unit vector after normalization
}

TEST(Vector3, MethodIsNormalized_ShouldReturnTrueWhenVectorIsNormalized)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    first.normalize();
    EXPECT_TRUE(first.isNormalized());
}

TEST(Vector3, MethodZero_ShouldReturnEmptyVector)
{
    my::math::Vector3 zeroes = my::math::Vector3::Zero();
    EXPECT_TRUE(zeroes.almostEquals(my::math::Vector3(0.0)));
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
    EXPECT_TRUE(result.almostEquals(my::math::Vector3(5.0)));
}

TEST(Vector3, AddScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0);
    my::math::Vector3 result = first + 1.0;
    EXPECT_TRUE(result.almostEquals(my::math::Vector3(2.0)));
}

TEST(Vector3, AddOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0);
    first += 1.0;
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(2.0)));
}

TEST(Vector3, SubtractScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    my::math::Vector3 result = first - 1.0;
    EXPECT_TRUE(result.almostEquals(my::math::Vector3(2.0)));
}

TEST(Vector3, SubtractOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    first -= 1.0;
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(2.0)));
}

TEST(Vector3, MultiplyScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    my::math::Vector3 result = first * 2.0;
    EXPECT_TRUE(result.almostEquals(my::math::Vector3(6.0)));
}

TEST(Vector3, MultiplyOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(3.0);
    first *= 2.0;
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(6.0)));
}

TEST(Vector3, DivideScalarToVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(6.0);
    my::math::Vector3 result = first / 2.0;
    EXPECT_TRUE(result.almostEquals(my::math::Vector3(3.0)));
}

TEST(Vector3, DivideOneScalarToOneVector_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(6.0);
    first /= 2.0;
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(3.0)));
}

TEST(Vector3, AddOneVectorToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    my::math::Vector3 second(4.0, 3.0, 2.0);
    first += second;
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(5.0)));
}

TEST(Vector3, AddMultipleVectorsToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(1.0, 2.0, 3.0);
    my::math::Vector3 second(4.0, 3.0, 2.0);
    first += second + second;
    EXPECT_TRUE(first.almostEquals({9.0, 8.0, 7.0}));
}

TEST(Vector3, SubtractTwoVectors_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0);
    my::math::Vector3 second(1.0);
    my::math::Vector3 result = first - second;
    EXPECT_TRUE(result.almostEquals(my::math::Vector3(1.0)));
}

TEST(Vector3, SubtractOneVectorToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0);
    my::math::Vector3 second(1.0);
    first -= second;
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(1.0)));
}

TEST(Vector3, SubtractMultipleVectorsToTheOther_WithOperator_ShouldWorkSuccessfully)
{
    my::math::Vector3 first(2.0);
    my::math::Vector3 second(1.0);
    first -= second - second;
    EXPECT_TRUE(first.almostEquals(my::math::Vector3(2.0)));
}
