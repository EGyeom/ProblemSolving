""" 
class Solution:
    def isPalindrome(self, s: str) -> bool:
        str = []
        for c in s:
            if c.isalnum():
                str.append(c.lower())
        print(str)
        while len(str) > 1:
            if str.pop(0) != str.pop():
                return False
        return True
"""
class Solution:
    def isPalindrome(self, s: str) -> bool:
        str = []
        for c in s:
            if c.isalnum():
                str.append(c.lower())
        if str != str[::-1]:
            return False
        return True

## 리스트 슬라이싱이 제일 빠르다
