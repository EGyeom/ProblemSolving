from typing import List

# class Solution:
#     def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
#         n = len(nums)
#         nums.sort()
#         dp = list()
#         origin = list()
#         max_index = 0
#         max_value = 0
#         for i in range(n):
#             dp.append(1)
#             origin.append(-1)
#             for j in range(i):
#                 if nums[i] % nums[j] == 0 :
#                     if dp[j] + 1 > dp[i]:
#                         dp[i] = dp[j] +1
#                         origin[i] = j
#             if max_value < dp[i]:
#                 max_value = dp[i]
#                 max_index = i
#         ans = list()
#         while max_index != -1:
#             ans.append(nums[max_index])
#             max_index = origin[max_index]
#         return ans

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        res = [[]]
        for i in sorted(nums):
            temp = []
            for j in res:
                if not j or i%j[-1] == 0:
                    temp.append(j + [i])
            res.append(max(temp, key = len))
        return max(res, key = len)

exam = [5,9,18,54,108,540,90,180,360,720]

s = Solution()

test = s.largestDivisibleSubset(exam)

for x in test:
    print(x)


# def largestDivisibleSubset(self, nums):
#     S = {-1: set()}
#     for x in sorted(nums):
#         S[x] = max((S[d] for d in S if x % d == 0), key=len) | {x}
#     return list(max(S.values(), key=len))