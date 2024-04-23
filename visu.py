import numpy as np
import matplotlib.pyplot as plt

# Function to load the occupancy grid from a CSV file
def load_occupancy_grid(file_path):
    return np.genfromtxt(file_path, delimiter=',', filling_values=0.0)

# Function to visualize the occupancy grid
def visualize_occupancy_grid(grid):
    plt.imshow(grid, cmap='Greys', interpolation='none', origin='lower')
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
