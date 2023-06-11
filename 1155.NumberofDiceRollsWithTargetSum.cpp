#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;

        std::unordered_map<int, int> cache;

        return helper(n, target, k, cache, MOD);
    }

    int helper(int n, int cursum, int k, std::unordered_map<int, int>& cache, const int MOD) {
        if (cursum < 0)
            return 0;
        if (n == 0) {
            if (cursum == 0)
                return 1;
            return 0;
        }

        int key = n * 1000 + cursum;
        if (cache.find(key) != cache.end())
            return cache[key];

        int res = 0;

        for (int i = 1; i <= k; ++i) {
            res = (res % MOD + helper(n - 1, cursum - i, k, cache, MOD) % MOD) % MOD;
        }

        cache[key] = res;
        return res;
    }
};

int main() {
    Solution solution;
    int n = 30;
    int k = 30;
    int target = 500;
    int result = solution.numRollsToTarget(n, k, target);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
