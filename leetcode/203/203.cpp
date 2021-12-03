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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* before = nullptr;
        ListNode* current = head;
        while(1)
        {
            if(current->val == val)
            {
                if(before == nullptr)
                {
                    head = head->next;
                    delete current;
                    current = head;
                }
                else
                {
                    before->next = current->next;
                    delete current;
                    current = before->next;
                }
            }
            else
            {
                before = current;
                current = current->next;
            }

            if(current == nullptr) break;
        }
        return head;
    }
};


/* class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode;
        dummy -> next = head;
        ListNode* curr = dummy;
        
        while(curr -> next) {
            if(curr -> next -> val == val) {
                curr -> next = curr -> next -> next;
            } else {
                curr = curr -> next;
            }
        }
        
        return dummy -> next;
    }
}; */


/* class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode* newNext = removeElements(head -> next, val);
        if(head -> val == val) {
            return newNext;
        } else {
            head -> next = newNext;
            return head;
        }
    }
}; */