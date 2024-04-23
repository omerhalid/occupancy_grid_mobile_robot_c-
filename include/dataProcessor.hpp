#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include "OccupancyGrid.hpp"
#include <string>

/**
 * @class DataProcessor
 * @brief A class for processing data for an occupancy grid.
 */
class DataProcessor {

public:
    /**
     * @brief Read data from a CSV file and populate the occupancy grid.
     * 
     * @param dataFile The name of the CSV file to read from.
     * @param grid The occupancy grid to populate with data.
     */
    void readCSVAndPopulateData(const std::string& dataFile, OccupancyGrid& grid);
};

#endif // DATAPROCESSOR_H
