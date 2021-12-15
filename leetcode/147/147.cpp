
#include <iostream>
#include <cstdio>

 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy= new ListNode(0,head);
        ListNode* start = head->next;
        while(start != nullptr)
        {
            ListNode * temp = dummy;
            while(temp->next != start)
            {
                if(temp->next->val > start->val)
                {
                    ListNode* check = temp->next;
                    temp->next = start;
                    check->next = start->next;
                    start->next = check;
                    start = check;
                    break;
                }
                temp = temp->next;
            }
            start = start->next;
        }
        return dummy->next;
    }
};