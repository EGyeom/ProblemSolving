# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head == None:
            return None
        dummy = ListNode(0,head)
        curr = dummy
        while curr.next != None:
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return dummy.next
        
        
# class Solution:
#     def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
#         if head == None:
#             return head
        
#         newNext = self.removeElements(head.next, val)
#         if head.val == val:
#             return newNext
#         else:
#             head.next = newNext
#             return head
        