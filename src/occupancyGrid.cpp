#include "../include/OccupancyGrid.hpp"
#include "../include/sensor.hpp"
#include <fstream>
#include <cmath>

OccupancyGrid::OccupancyGrid() 
    : occupancyGrid(100, std::vector<double>(100, 0)) {} // 10m / 0.1m resolution = 100 cells


Position OccupancyGrid::calculateCenterPosition(int row, int column) {
    double cellX = (row * gridResolution + gridResolution / 2.0 - mapWidth / 2.0);
    double cellY = (column * gridResolution + gridResolution / 2.0 - mapHeight / 2.0);
    return Position{cellX, cellY};
}

std::pair<double, double> OccupancyGrid::calculateDistanceAndAngle(double robotX, double robotY, double robotTheta, Position cellCenter) {
    double cellX = cellCenter.x;
    double cellY = cellCenter.y;

    // Calculate the distance and angle from the robot to the cell
    double deltaX = cellX - robotX;
    double deltaY = cellY - robotY;
    double distanceToCell = sqrt(deltaX * deltaX + deltaY * deltaY);
    // atan2 returns the angle in the range [-pi, pi], so we need to adjust it to [0, 2pi]
    double angleToCell = atan2(deltaY, deltaX) - robotTheta;

    return std::make_pair(distanceToCell, angleToCell);
}

void OccupancyGrid::updateGrid(double robotX, double robotY, double robotTheta, const double* sensorData) {
    // Convert sensor data from time of flight to distance in meters
    // Assuming speed of sound = 343 m/s in air at 20 degrees Celsius
    double sensorDistances[4];
    for (int i = 0; i < 4; ++i) {
        sensorDistances[i] = sensorData[i] * 343.0 / 2; // Divide by 2 to account for round trip of sound
    }

    // Update the occupancy grid
    for (int row = 0; row < mapWidth / gridResolution; ++row) {
        for (int column = 0; column < mapHeight / gridResolution; ++column) {
            // Calculate the center position of the current grid cell
            Position cellCenter = calculateCenterPosition(row, column);
            // Calculate the distance and angle from the robot to the cell
            auto [distanceToCell, angleToCell] = calculateDistanceAndAngle(robotX, robotY, robotTheta, cellCenter);

            // Update the cell based on sensor readings
            for (int k = 0; k < 4; ++k) {
                double sensorAngleToCell = angleToCell - (Sensor::sensorAngleOffset + k * M_PI / 2);
                if (sensorAngleToCell >= -Sensor::sensorAngle / 2 && sensorAngleToCell <= Sensor::sensorAngle / 2) {
                    if (distanceToCell <= sensorDistances[k]) {
                        // Mark as occupied (1.0) if the cell is within the sensor range
                        occupancyGrid[row][column] = 1.0;
                    }
                }
            }
        }
    }
}

void OccupancyGrid::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }
    for (const auto &row : occupancyGrid) {
        for (const auto &cell : row) {
            outFile << cell << ',';
        }
        outFile << '\n';
    }
    outFile.close();
}
