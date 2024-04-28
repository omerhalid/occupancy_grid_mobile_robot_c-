/**
 * @mainpage Occupancy Grid Mapping Documentation
 *
 * @section intro Introduction
 * This project develops a software in C++ designed to create an occupancy grid, also known as an obstacle map, from detections sourced from ultrasonic sensors mounted on a robot. This map is crucial for robotic navigation and environment interaction, especially in autonomous tasks.
 *
 * @section project_desc Project Description
 * This project constructs an occupancy grid by integrating readings from four ultrasonic sensors positioned at the corners of a robot's chassis, each aligned at 45 degrees with respect to the robot’s axis. These sensors measure the environment within a 30-degree wide cone by emitting sound waves and detecting their echo.
 * 
 * The robot is additionally equipped with a 'magical' odometry sensor that provides precise x- and y-coordinates and orientation angles (in radians), starting from zero upon activation. This data, along with timestamps and sensor readings (time of flight in seconds), is processed from a CSV file to map the surrounding obstacles.
 *
 * @section file_overview File Overview
 * - `main.cpp`: Initializes the data processor and occupancy grid, reads sensor data from a CSV file, and outputs the occupancy grid to a file.
 * - `dataProcessor.hpp/cpp`: Defines methods for reading the CSV file and updating the occupancy grid based on sensor readings.
 * - `occupancyGrid.hpp/cpp`: Contains the OccupancyGrid class which manages the grid data structure and performs calculations for mapping.
 * - `sensor.hpp`: Defines sensor properties including angle offsets and field of view.
 * - `position.hpp`: Simple structure to represent 2D positions.
 *
 * \subsection data_proc_sec DataProcessor Class
 * 
 * - **CSV Data Reading**: The DataProcessor class is responsible for reading a CSV file containing the robot's sensory and positional data. The CSV file includes timestamps, robot coordinates, orientation, and sensor time-of-flight data.
 * - **Data Parsing and Grid Population**: After opening the CSV file, it iterates over each line, parsing the data into relevant double values. These values are then used to update the occupancy grid based on the robot's position and the sensor data.
 * 
 * \subsection occ_grid_sec OccupancyGrid Class
 * 
 * - **Grid Initialization**: The OccupancyGrid class initializes a 2D vector representing the grid. Each cell within this grid corresponds to a 10 cm x 10 cm area of the physical space the robot navigates.
 * - **Center Position Calculation**: For each cell in the grid, its center position is calculated using its row and column indices. This helps in determining the exact location of the cell in relation to the robot.
 * - **Distance and Angle Calculation**: For each cell, the Euclidean distance and the angle relative to the robot’s orientation are calculated. These calculations are crucial for determining whether a cell lies within the sensor's effective range and field of view.
 * 
 * \subsection algo_steps_sec Detailed Algorithmic Steps
 * 
 * - **Converting Sensor Time-of-Flight to Distance**: The time-of-flight data from each sensor is converted into distance using the formula distance = (time_of_flight * speed_of_sound) / 2. This conversion is necessary to understand how far away an object is based on the time it takes for the sound to return to the sensor.
 * - **Iterative Grid Update**: The entire grid is iterated through, cell by cell. For each cell, calculate its center's position relative to the robot. Calculate the distance and angle from the robot to the center of the cell. For each sensor on the robot, adjust the angle considering the sensor’s orientation offset and the robot’s heading. Determine if the cell lies within the field of view of any sensor by checking if the absolute angle difference is within half the sensor's beam angle. If a cell is within the sensor's range and field of view, and the calculated distance to the cell is less than or equal to the sensor's measured distance, mark it as occupied (1.0).
 * - **Finalizing the Grid**: After all cells have been evaluated, the grid is saved to a CSV file. This file stores the occupancy status (0 for free, 1 for occupied) of each cell, providing a visual representation of the area around the robot.
 * 
 * \section conclusion_sec Conclusion
 * 
 * This approach ensures that all areas within the sensors' range are assessed for potential obstacles, providing a comprehensive map of the environment. The resulting occupancy grid is crucial for tasks such as path planning and navigation in robotics. The final grid is outputted as a CSV file, which can be used for further analysis or real-time navigation purposes. You can access the generated CSV file in the `debug` folder.
 *
 * @image html robot_test.png "Occupancy Grid Image"
 * 
 * @section usage Usage
 * This project uses CMake as its build system. To compile and run the project, follow these steps:
 * 
 * 1. Open a terminal in the project's root directory.
 * 2. Create a new directory named `build` and navigate into it: `mkdir build && cd build`
 * 3. Run CMake to generate the build files: `cmake ..`
 * 4. Compile the project: `cmake --build .`
 * 5. Navigate to the `debug` directory: `cd debug`
 * 6. Run the executable with the path to the input CSV file specified: `.\main.exe`
 * 
 * Note: Don't forget to change the directory path of the `robot1.csv` in order to run and compile it successfully.
 * 
 * The output will be an occupancy grid saved in CSV format, representing detected obstacles.
 * 
 * To visualize the grid, you can run ./visu.py in the main directory. This script will generate a heatmap of the occupancy grid using matplotlib.
 * 
 * To run the test cases, after compiling the code navigate to the `debug` directory and run .\runUnitTests.exe`
 *
 * Note: This project requires a C++17 or later compiler and has dependencies on Google Test, Python 3 or later, and NumPy. Make sure all dependencies are resolved before compiling. The project is configured to use the same runtime library for Google Test as your code to avoid conflicts.
 * 
 *\section references_sec References
 * 
 * [1] "Occupancy Grids, MathWorks", https://www.mathworks.com/help/robotics/ug/occupancy-grids.html
 * 
 * [2] "What is an Occupancy Grid Map?", https://automaticaddison.com/what-is-an-occupancy-grid-map/
 * 
 * [3] "Time-of-Flight principle", https://www.terabee.com/time-of-flight-principle/#:~:text=The%20Time%2Dof%2DFlight%20principle%20(ToF)%20is%20a,being%20reflected%20by%20an%20object.
 * 
 */
