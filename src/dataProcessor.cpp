#include "../include/dataProcessor.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void DataProcessor::readCSVAndPopulateData(const std::string& dataFile, OccupancyGrid& grid) {
    std::cout << "Opening file: " << dataFile << std::endl;
    std::ifstream dataStream(dataFile);
    if (!dataStream.is_open()) {
        throw std::runtime_error("Could not open file " + dataFile);
    }

    std::string line;
    
    // Skip the header line
    getline(dataStream, line);

    while (getline(dataStream, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<double> parsedData;
        std::cout << "Parsing line: " << line << std::endl;

        while (getline(lineStream, cell, ',')) {
            try {
                parsedData.push_back(stod(cell));
            } catch (std::invalid_argument& e) {
                throw std::runtime_error("Could not convert string to double: " + cell);
            }
        }
        
        // data format is: timestamp, pos_x, pos_y, heading, ultrasound0, ultrasound1, ultrasound2, ultrasound3
        if (parsedData.size() < 8) {
            throw std::runtime_error("Not enough data in line: " + line);
        }

        double timestamp = parsedData[0];
        double robotX = parsedData[1];
        double robotY = parsedData[2];
        double robotTheta = parsedData[3];
        double sensorData[4] = {parsedData[4], parsedData[5], parsedData[6], parsedData[7]};
        
        std::cout << "Updating occupancy grid" << std::endl;
        // Update the occupancy grid based on the sensor data
        grid.updateGrid(robotX, robotY, robotTheta, sensorData);
    }
}
