/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * doubleNext = head;
        while(doubleNext != nullptr && doubleNext->next != nullptr)
        {
            head = head->next;
            doubleNext= doubleNext->next->next;
        }
        return head;
    }
};