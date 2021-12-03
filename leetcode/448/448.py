# Input: nums = [4,3,2,7,8,2,3,1]
# Output: [5,6]
from typing import List
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        list_size = len(nums)
        for i in range(list_size):
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1])
        return [ i+1 for i in range(list_size) if nums[i] > 0]

s = Solution()

print(s.findDisappearedNumbers([4,3,2,7,8,2,3,1]))
