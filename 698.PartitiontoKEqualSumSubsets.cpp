#include<vector>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int totalSum = 0;

        for (auto num : nums) {
            totalSum += num;
        }

        if (nums.size() < k) return false;
        if (totalSum % k != 0) return false;

        int targetSum = totalSum / k;

        vector<int> subsets(k, targetSum);

        return dfs(0, subsets, nums);
    }

    bool dfs(int i, vector<int>& subsets, vector<int>& nums) {

        if (i == nums.size()) return true;

        for (int j = 0; j < subsets.size(); j++) {
            if (j > 0 and subsets[j] == subsets[j-1]) continue;
            if (subsets[j] >= nums[i]) {
                subsets[j] -= nums[i];
                if (dfs(i+1, subsets, nums)) return true;

                subsets[j] += nums[i];
                
            }
        }

        return false;


    }
};