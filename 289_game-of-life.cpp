// This is copied from greeksgreek.com
// it's simple two level iterative , use recorsion of matrix example from our sample. 
#include <bits/stdc++.h>
using namespace std;
 
void print(vector<vector<int>> grid)
{
    int p = grid.size(),
    q = grid[0].size();
     
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < q; j++) {
     
        cout << grid[i][j];
     }
    cout << endl;
    }
}       


// Function to check if
// index are not out of grid
static bool save(vector<vector<int> > grid,int row, int col)
{
    return (grid.size() > row && grid[0].size() > col && row >= 0 && col >= 0);
}
    // Function to get New Generation
void solve(vector<vector<int> >& grid)
{
      int p = grid.size(),
        q = grid[0].size();
      int u[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
      int v[] = { 0, 0, -1, -1, -1, 1, 1, 1 };
     for (int i = 0; i < p; i++)
     {
      for (int j = 0; j < q; j++)
      {
      // IF the initial value
      // of the grid(i, j) is 1
      if (grid[i][j] > 0)
      {
        for (int k = 0; k < 8; k++)
        {
          if (save(grid, i + u[k],
                   j + v[k]) &&
                   grid[i + u[k]][j + v[k]] > 0)
          {
            // If initial value > 0,
            // just increment it by 1
            grid[i][j]++;
          }
        }
      }
  
      // IF the initial value
      // of the grid(i, j) is 0
      else
      {
         for (int k = 0; k < 8; k++)
         {
           if (save(grid, i + u[k],
                   j + v[k]) &&
                   grid[i + u[k]][j + v[k]] > 0)
              {
                // If initial value <= 0
                // just decrement it by 1
                grid[i][j]--;
              }
           }
        }
      }
    }
  
    // Generating new Generation.
    // Now the magnitude of the
    // grid will represent number
    // of neighbours
    for (int i = 0; i < p; i++)
      {
          for (int j = 0; j < q; j++)
         {
        // If initial value was 1.
        if (grid[i][j] > 0)
        {
            // Since Any live cell with
          // < 2 live neighbors dies
           if (grid[i][j] < 3)
              grid[i][j] = 0;
  
             // Since Any live cell with
            // 2 or 3 live neighbors live
           else if (grid[i][j] <= 4)
            grid[i][j] = 1;
  
            // Since Any live cell with
             // > 3 live neighbors dies
            else if (grid[i][j] > 4)
              grid[i][j] = 0;
        }
       else
        {
        // Since Any dead cell with
        // exactly 3 live neighbors
        // becomes a live cell
         if (grid[i][j] == -3)
              grid[i][j] = 1;
         else
              grid[i][j] = 0;
            }
        }
     }
}
// Driver code
int main ()
{
  vector<vector<int>> grid = {
	  	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
  solve(grid);
  
  // Displaying the grid
  print(grid);
  return 0;
}

