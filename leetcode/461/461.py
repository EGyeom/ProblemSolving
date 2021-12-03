class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        result = x ^ y
        cnt = 0
        while result != 0:
            cnt += result & 1
            result = result >> 1
        return cnt