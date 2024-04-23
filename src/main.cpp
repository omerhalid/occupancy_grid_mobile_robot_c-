#include "../include/dataProcessor.hpp"
#include "../include/occupancyGrid.hpp"

#include <iostream>

int main() {
    DataProcessor processor;
    OccupancyGrid grid;

    // File path to the CSV file
    std::string dataFile = "C:\\Users\\katka\\source\\continental_task_omer_cinar\\src\\robot1.csv";
    std::cout << "Reading file: " << dataFile << std::endl;
    processor.readCSVAndPopulateData(dataFile, grid);

    try {
        grid.saveToFile("occupancy_grid2.csv");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
