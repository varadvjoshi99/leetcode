#include<vector>

using namespace std; 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;

        while (l < r) {

            int mid = (l + r) / 2;

            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        int peak = l-1;

        int s1 = binSearch(nums, 0, peak, target);

        if (s1 != -1) return s1;

        int s2 = binSearch(nums, l, nums.size() - 1, target); 

        if (s2 != -1) return s2;

        return -1;

    }

    int binSearch(vector<int>& nums, int l, int r, int target) {

        while (l <= r) {
            
            int mid = (l + r) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }

};