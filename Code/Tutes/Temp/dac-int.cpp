//g++  5.4.0

#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <time.h>

using namespace std;

int grid[5][5];

//
int grains = 500;

bool isCellValid(int r, int c)
{
    return r >= 0 and r < 5 and c >=0 and c < 5;
}

void simulation(int numGrains)
{
    srand (time(NULL));

    for (int _ = 0; _ < numGrains; ++_)
    {
        int r = rand() % 5;
        int c = rand() % 5;
    
        grid[r][c]+=1;
        
        bool isSatisfied = false;
        while (!isSatisfied)
        {
            int delta[4][2] = {
                {1, 0}, //down
                {-1, 0}, //up
                {0, -1}, //left
                {0, 1} //right
            };
            for (int cur_row = 0; cur_row < 5; ++cur_row)
            {
                for (int cur_col = 0; cur_col < 5; ++cur_col)
                {
                    while (grid[cur_row][cur_col] >= 4)
                    {
                        grid[cur_row][cur_col] -= 4;
                        for (int direction = 0; direction < 4; ++direction)
                        {
                            int next_row = cur_row + delta[direction][0];
                            int next_col = cur_col + delta[direction][1];
                            if (isCellValid(next_row, next_col))
                            {
                                grid[next_row][next_col]++;
                            }
                        }
                    }
                }
            }
            isSatisfied = true;
            for (int r = 0; r < 5; ++r)
            {
                for (int c = 0; c < 5; ++c)
                {
                    isSatisfied  = isSatisfied and (grid[r][c] <= 3);             
                }
            }
        }
        int resultSum = 0;
        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c < 5; ++c)
            {
                resultSum += grid[r][c];
            }
        }
        cout << resultSum << endl;    
        
    }
    vector<int> arraySum;
}

int main()
{
    simulation(500);
    std::cout << "Hello, world!\n";
}