from typing import *
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        new_head = dummy
        carry = 0
        while l1 or l2 or carry :
            if l1 != None:
                carry += l1 and l1.val or 0
                l1 = l1.next
            if l2 != None:
                carry += l2 and l2.val or 0
                l2 = l2.next
            dummy.next = ListNode((carry%10))
            carry //= 10
            dummy = dummy.next
        return new_head.next

a = Solution()
# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
result = a.addTwoNumbers(ListNode(2,ListNode(4,ListNode(3))),ListNode(5,ListNode(6,ListNode(4))))

while result:
    print(result.val)
    result = result.next

""" reference code -- learned things from this problems chained assignment, quotient, remainder =divmod(val, divider)
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        new_head = dummy
        carry = 0
        while l1 or l2 or carry :
            if l1 != None:
                carry += l1 and l1.val or 0
                l1 = l1.next
            if l2 != None:
                carry += l2 and l2.val or 0
                l2 = l2.next
            carry, val = divmod(carry, 10)
            dummy.next = dummy = ListNode(val)
        return new_head.next
 """