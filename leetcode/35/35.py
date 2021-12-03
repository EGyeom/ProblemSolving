from typing import List, int
def searchInsert(nums: List[int], target: int)-> int:
    left = 0
    right = len(nums) -1
    middle = 0
    while left <= right :
        middle = (left + right) // 2
        if target < nums[middle] :
            right = middle - 1
        elif target > nums[middle] :
            left = middle + 1
        else :
            return nums[middle]
    if target > nums[middle] :
        return middle +1
    else:
        return middle