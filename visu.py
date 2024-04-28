#The function load_occupancy_grid(file_path) uses np.genfromtxt to read the CSV file into a NumPy array. 
#Each value in the CSV (typically 0 or 1, representing free or occupied spaces respectively) is loaded into the corresponding cell in the NumPy array.

#plt.imshow() is the function used to display the data. The grid parameter is the NumPy array loaded from the CSV file.

import numpy as np
import matplotlib.pyplot as plt

# Function to load the occupancy grid from a CSV file
def load_occupancy_grid(file_path):
    return np.genfromtxt(file_path, delimiter=',', filling_values=0.0)

# Function to visualize the occupancy grid
def visualize_occupancy_grid(grid):
    # The cmap='Greys' parameter sets the color map to "Greys", which displays lower values as lighter shades and higher values as darker shades. 
    # Since occupied cells have a value of 1, they appear as black in this grayscale map, and free cells (0) appear as white
    plt.imshow(grid, cmap='Greys', interpolation='none', origin='lower')
    # origin='lower' sets the [0, 0] index of the array to appear at the bottom-left corner of the plot, 
    # making the visualization align with typical Cartesian coordinates used in most mapping systems.
    plt.colorbar(label='Occupancy')
    plt.title('Occupancy Grid Map')
    plt.xlabel('X Coordinate')
    plt.ylabel('Y Coordinate')
    plt.show()

if __name__ == '__main__':
    # Load the occupancy grid from the file (replace with your file path)
    occupancy_grid_file_path = 'C:\\Users\\katka\\source\\continental_task_omer_cinar\\build\\Debug\\occupancy_grid5.csv'
    occupancy_grid = load_occupancy_grid(occupancy_grid_file_path)
    
    # Visualize the occupancy grid
    visualize_occupancy_grid(occupancy_grid)
