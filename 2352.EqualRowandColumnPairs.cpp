#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        map<string, int> counter;

        for (int i = 0; i < grid.size(); i++ ) {
            string hash = getHash(grid[i]);
            counter[hash]++;

        }

        int res = 0;

        for (int j = 0; j < grid[0].size(); j++) {

            vector<int> cols{};
            for (int i = 0; i < grid.size(); i++) {
                cols.push_back(grid[i][j]);
            }

            string hash = getHash(cols);

            if (counter.find(hash) != counter.end()) {
                res += counter[hash];
            }
        }

        return res;
    }

    string getHash(vector<int>& nums) {

        string res = "";

        for (int i = 0; i < nums.size(); i++) {
            res = res + " " + to_string(nums[i]);
        }

        return res;
    }
};