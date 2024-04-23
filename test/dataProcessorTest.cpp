#include <gtest/gtest.h>
#include "dataProcessor.hpp"
#include "occupancyGrid.hpp"

// Test fixture for DataProcessor
class DataProcessorTest : public ::testing::Test {
protected:
    DataProcessor processor;
    OccupancyGrid grid;
};

TEST_F(DataProcessorTest, ReadCSVAndPopulateData) {
    // This would normally read from a file, consider using a stringstream as a mock file
    std::string testCSV = "timestamp,pos_x,pos_y,heading,ultrasound0,ultrasound1,ultrasound2,ultrasound3\n"
                          "123,5,5,0,1.0,1.0,1.0,1.0\n";
    std::stringstream ss(testCSV);
    EXPECT_NO_THROW(processor.readCSVAndPopulateData(ss.str(), grid));
    // Assertions to check if the grid was populated correctly would go here
}
