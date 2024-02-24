from typing import List 

class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        
        nums.sort()
        min_high_score = min(nums[-2] - nums[1], nums[-1] - nums[2], nums[-3] - nums[0])
        
        return min_high_score
