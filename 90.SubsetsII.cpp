#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vvi result;
        vi subset;

        sort(nums.begin(), nums.end());
        dfs(0, subset, result, nums);

        return result;
    }

    void dfs(int i, vi& subset, vvi& result, vi& nums) {
        
        result.push_back(subset);
        if (i == nums.size()) {
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue;
            else {
                subset.push_back(nums[j]);
                dfs(j+1, subset, result, nums);
                subset.pop_back();
            }
            // dfs(j+1, subset, result, nums);
        }

        return;
    }
};