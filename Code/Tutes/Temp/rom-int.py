#python 3.5.2
import numpy as np
from random import randint

# 0 grids
grid = np.zeros((5,5))

check_steady = True

def is_steady():
    for i in grid:
        for j in i:
            if j > 3:
                return False
def cascade(grid):
    for rows in range(5):
        for cols in range(5):
            if grid[rows][cols] == 4:
                grid[rows][cols] = 0
                grid[rows][cols + 1] += 1
                grid[rows][cols - 1] += 1
                if rows == 0:
                    grid[rows + 1][cols] += 1
                elif rows == 4:
                    grid[rows - 1][cols] += 1 
                else:
                    grid[rows + 1][cols] += 1
                    grid[rows - 1][cols] += 1
                
    return grid


# dropping sand onto the matrix using random indexing
# using loop to a large number of drop
for i in range(500):
    x = randint(0, 4)
    y = randint(0, 4)
    
    grid[x][y] += 1
    
    check_steady = is_steady()
    
    while check_steady == False:
        grid = cascade(grid)
        
        check_steady = is_steady()

