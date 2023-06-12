#include<map>

using namespace std;

class Solution {
public:

    map<int, int> memo;
    int numTrees(int n) {
        
        if (memo.find(n) != memo.end()) return memo[n];
        if (n <= 1) return 1;
        int res = 0;
        
        for (int i = 1; i <= n; i++) {
            res += numTrees(i-1) * numTrees(n-i);
        }

        memo[n] = res;
        return res;
    }
};