#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int j = 0, i = 0; j < n; j++) {
            dfs(i, j, heights, pacific);
        } 

        for (int j = 0, i = 0; i < m; i++) {
            dfs(i, j, heights, pacific);
        } 

        for (int j = 0, i = m-1; j < n; j++) {
            dfs(i, j, heights, atlantic);
        } 

        for (int j = n-1, i = 0; i < m; i++) {
            dfs(i, j, heights, atlantic);
        } 

        vvi result; 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << i << " " << j << " " << pacific[i][j] << " " << atlantic[i][j] << endl;
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(int i, int j, vvi& heights, vector<vector<bool>>& visited) {

        vector<pii> neigh{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        if (visited[i][j]) return;
        visited[i][j] = true;

        for (auto dir : neigh) {
            int x = i + dir.first, y = j + dir.second;
            if ( x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && !visited[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(x, y, heights, visited);

            }
        }
        
        return ;
    }
};