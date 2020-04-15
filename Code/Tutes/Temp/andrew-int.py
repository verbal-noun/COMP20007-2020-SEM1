#python 3.5.2

import random

#initialize the grid table
grid = [[0 for i in range(5)] for j in range(5)]

def stable_check(grid):
    state=True
    for rows in range(len(grid)):
        for cols in range(len(grid)):
            if grid[rows][cols]>3:
                cascade_cell(rows,cols,grid)

def cascade_cell(row,col,grid):
    nearby_cells=[(0,1),(0,-1),(-1,0),(1,0)]
    grid[row][col]=0
    for cell in nearby_cells:
        if ((row+cell[0])>4 or (col+cell[1])>4 or
            (row+cell[0])<0 or (col+cell[1])<0):
            continue
        grid[row+cell[0]][col+cell[1]]+=1
        if grid[row+cell[0]][col+cell[1]]>3:
           cascade_cell(row+cell[0],col+cell[1],grid)

for i in range(500):
    row=random.randint(0,4)
    col=random.randint(0,4)
    grid[row][col]+=random.randint(0,4)
    stable_check(grid)
    for i in range(len(grid)):
        for j in range(len(grid)):
            sum+=grid[i][j]
    print(grid)
    print()