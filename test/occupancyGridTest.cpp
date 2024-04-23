#include "gtest/gtest.h"
#include "../include/OccupancyGrid.hpp"

static constexpr float PRECISION = 1e-1;

class OccupancyGridTest : public ::testing::Test, public OccupancyGrid {
protected:
    void SetUp() override {
        // This method is called before each test
    }

    void TearDown() override {
        // This method is called after each test
    }
};

TEST_F(OccupancyGridTest, TestCalculateCenterPosition) {
    Position center = calculateCenterPosition(5, 5);
    EXPECT_NEAR(center.x, -4.5, PRECISION);
    EXPECT_NEAR(center.y, -4.5, PRECISION);
}

TEST_F(OccupancyGridTest, TestCalculateDistanceAndAngle) {
    Position cellCenter{0.5, 0.5};
    auto [distance, angle] = calculateDistanceAndAngle(0.0, 0.0, 0.0, cellCenter);
    EXPECT_NEAR(distance, sqrt(0.5 * 0.5 + 0.5 * 0.5), PRECISION);
    EXPECT_NEAR(angle, atan2(0.5, 0.5), PRECISION);
}

// TEST_F(OccupancyGridTest, TestUpdateGrid) {
//     double sensorData[4] = {0.0, 0.0, 0.0, 0.0};
//     updateGrid(0.0, 0.0, 0.0, sensorData);
//     // Add assertions to check the state of the occupancy grid
// }

// TEST_F(OccupancyGridTest, TestSaveToFile) {
//     saveToFile("test.txt");
//     // Add code to open the file and check its contents
// }