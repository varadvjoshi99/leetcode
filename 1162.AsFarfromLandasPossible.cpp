#include<vector>
#include<queue>
#include<utility>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        vector<vector<int>> neigh{{1,0}, {-1,0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {
                q.push(make_pair(i, j));

                // cout << i << ' ' << j << endl;
            }

            }
        }
        

        int dist = 0; 

        while (q.size()) {

            int k = q.size();
            // dist += 1;
            bool found = false;
            for (int i = 0; i < k; i++ ){
                
                auto front = q.front();
                q.pop();

                int x = front.first, y = front.second;

                for (auto nei: neigh) {

                    int xx = x + nei[0], yy = y + nei[1];
                    if (xx < m && xx >= 0 && yy < n && yy >= 0 && grid[xx][yy] == 0) {
                        grid[xx][yy] = 1;
                        found = true;
                        // cout << xx << ' ' << yy << ' ' << dist << endl;
                        q.push(make_pair(xx, yy));

                    }
                }
            }
            if (found) dist += 1;

        }
        
        return (dist > 0) ? dist: -1;

    }
};