// #include <gtest/gtest.h>
// #include "dataProcessor.hpp"
// #include "occupancyGrid.hpp"

// // Mock classes or additional includes might be necessary depending on how
// // your system interacts with external systems (like file I/O).
    
// // Test fixture for OccupancyGrid
// class OccupancyGridTest : public ::testing::Test {
// protected:
//     OccupancyGrid grid;

//     // You can set up the grid here if needed, like custom sizes or resolutions.
//     void SetUp() override {
//         // grid setup code here
//     }
// };

// TEST_F(OccupancyGridTest, GridInitialization) {
//     EXPECT_EQ(grid.getOccupancyGrid().size(), 100);  // Assuming 100x100 grid based on the default constructor
// }

// TEST_F(OccupancyGridTest, UpdateGrid) {
//     double sensorData[4] = {1.0, 1.0, 1.0, 1.0};  // Example sensor distances
//     grid.updateGrid(5.0, 5.0, 0.0, sensorData);  // Robot in the center, facing north
//     // Check specific grid cells to see if they have been marked correctly
//     EXPECT_EQ(grid.getOccupancyGrid()[50][50], 1.0);  // Check the center cell
// }
