// source : https://www.tutorialspoint.com/shortest-distance-from-all-buildings-in-cplusplus#:~:text=0%20represents%20an%20empty%20land,which%20we%20cannot%20pass%20through.



int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
   int shortestDistance(vector<vector<int>>& grid) {
      int ret = INT_MAX;
      int n = grid.size();
      int m = grid[0].size();
      int numberOfOnes = 0;
      vector < vector <int> > dist(n, vector <int>(m));
      vector < vector <int> > reach(n, vector <int>(m));
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
               numberOfOnes++;
               queue < pair <int, int> > q;
               q.push({i, j});
               set < pair <int, int> > visited;
               for(int lvl = 1; !q.empty(); lvl++){
                  int sz = q.size();
                  while(sz--){
                     pair <int, int> curr = q.front();
                     q.pop();
                     int x = curr.first;
                     int y = curr.second;
                     for(int k = 0; k < 4; k++){
                        int nx = x + dir[k][0];
                        int ny = y + dir[k][1];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited.count({nx, ny}) || grid[nx][ny] != 0) continue;
                        visited.insert({nx, ny});
                        dist[nx][ny] += lvl;
                        reach[nx][ny]++;
                        q.push({nx, ny});
                     }
                  }
               }
            }
         }
      }
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            if(grid[i][j] == 0 && reach[i][j] == numberOfOnes){
               ret = min(ret, dist[i][j]);
            }
         }
      }
      return ret == INT_MAX ? -1 : ret;
   }
};

