#include "../include/dataProcessor.hpp"
#include "../include/occupancyGrid.hpp"

#include <iostream>

int main() {
    // Create a DataProcessor object
    DataProcessor processor;

    // Create an OccupancyGrid object
    OccupancyGrid grid;

    // File path to the CSV file
    std::string dataFile = "C:\\Users\\katka\\source\\continental_task_omer_cinar\\src\\robot1.csv";

    // Print the file path to the console
    std::cout << "Reading file: " << dataFile << std::endl;

    // Read the CSV file and populate the occupancy grid
    processor.readCSVAndPopulateData(dataFile, grid);

    try {
        // Save the occupancy grid to a file
        grid.saveToFile("occupancy_grid5.csv");
    } catch (std::runtime_error& e) {
        // Print any errors that occurred while saving the file
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
