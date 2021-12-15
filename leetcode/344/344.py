from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        sSize = len(s)
        for i in range(sSize//2):
            s[i], s[-i-1] = s[-i-1], s[i]