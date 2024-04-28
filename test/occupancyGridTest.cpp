#include "gtest/gtest.h"
#include "../include/OccupancyGrid.hpp"

/**
 * @brief A constant to define the precision for floating point comparisons in the tests.
 * This is used in the EXPECT_NEAR assertions to allow for small differences due to floating point arithmetic.
 */
static constexpr double PRECISION = 1e-1;

/**
 * @class OccupancyGridTest
 * @brief Test fixture for testing the OccupancyGrid class.
 */
class OccupancyGridTest : public ::testing::Test, public OccupancyGrid {
protected:
    void SetUp() override {}
};

/**
 * @test TestCalculateCenterPosition
 * @brief Test to verify the calculateCenterPosition method.
 * This test checks the case where the row and column are both 5.
 * The expected center position is (-4.5, -4.5).
 */
TEST_F(OccupancyGridTest, TestCalculateCenterPosition) {
    Position center = calculateCenterPosition(5, 5);
    EXPECT_NEAR(center.x, -4.5, PRECISION);
    EXPECT_NEAR(center.y, -4.5, PRECISION);
}

/**
 * @test TestCalculateDistanceAndAngle
 * @brief Test to verify the calculateDistanceAndAngle method.
 * This test checks the case where the cell center is at (0.5, 0.5) and the robot is at the origin.
 * The expected distance is sqrt(0.5 * 0.5 + 0.5 * 0.5) and the expected angle is atan2(0.5, 0.5).
 */
TEST_F(OccupancyGridTest, TestCalculateDistanceAndAngle) {
    Position cellCenter{0.5, 0.5};
    auto [distance, angle] = calculateDistanceAndAngle(0.0, 0.0, 0.0, cellCenter);
    EXPECT_NEAR(distance, sqrt(0.5 * 0.5 + 0.5 * 0.5), PRECISION);
    EXPECT_NEAR(angle, atan2(0.5, 0.5), PRECISION);
}

/**
 * @test TestCalculateDistanceAndAngleNegative
 * @brief Test to verify the calculateDistanceAndAngle method with negative inputs.
 * This test checks the case where the cell center is at (-0.5, -0.5) and the robot is at the origin.
 * The expected distance is sqrt(0.5 * 0.5 + 0.5 * 0.5) and the expected angle is atan2(-0.5, -0.5).
 */
TEST_F(OccupancyGridTest, TestCalculateDistanceAndAngleNegative) {
    Position cellCenter{-0.5, -0.5};
    auto [distance, angle] = calculateDistanceAndAngle(0.0, 0.0, 0.0, cellCenter);
    EXPECT_NEAR(distance, sqrt(0.5 * 0.5 + 0.5 * 0.5), PRECISION);
    EXPECT_NEAR(angle, atan2(-0.5, -0.5), PRECISION);
}
