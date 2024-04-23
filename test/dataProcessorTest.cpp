#include "../include/dataProcessor.hpp"
#include "../include/OccupancyGrid.hpp"
#include <gtest/gtest.h>
#include <fstream>

class DataProcessorTest : public ::testing::Test, public DataProcessor {
protected:
    DataProcessor processor;
    OccupancyGrid grid;
};

TEST_F(DataProcessorTest, ReadCSVAndPopulateData_NoThrow) {
    std::string dataFile = "C:\\Users\\katka\\source\\continental_task_omer_cinar\\src\\robot1.csv";
    EXPECT_NO_THROW(processor.readCSVAndPopulateData(dataFile, grid));
}

TEST_F(DataProcessorTest, CheckFirstRowOfCSV) {
    std::string dataFile = "C:\\Users\\katka\\source\\continental_task_omer_cinar\\src\\robot1.csv";
    std::ifstream file(dataFile);

    ASSERT_TRUE(file.is_open());

    std::string line;
    std::getline(file, line); // Skip the header line
    std::getline(file, line); // Read the first line

    std::stringstream ss(line);
    std::string item;

    std::vector<std::string> row;
    while (std::getline(ss, item, ',')) {
        row.push_back(item);
    }

    // Check the values
    EXPECT_EQ(std::stoi(row[0]), 10);
    EXPECT_NEAR(std::stod(row[1]), 0.25, 1e-6);
    EXPECT_NEAR(std::stod(row[2]), 3.742, 1e-6);
    EXPECT_NEAR(std::stod(row[3]), -1.570796327, 1e-6);
    EXPECT_NEAR(std::stod(row[4]), 0.00133018, 1e-6);
    EXPECT_NEAR(std::stod(row[5]), 0.001773574, 1e-6);
    EXPECT_NEAR(std::stod(row[6]), 0.00133018, 1e-6);
    EXPECT_NEAR(std::stod(row[7]), 0.00133018, 1e-6);
}
