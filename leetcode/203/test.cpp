#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
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
int main()
{
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    for(int i = 1; i <= 5; i++)
    {
        current->next = new ListNode(i);
        current= current->next;
    }
    ListNode* test;
    while(test != nullptr)
    {
        std::cout << test->val << "\n";
        test= test->next;
    } 

    Solution s;
    test = s.removeElements(head,1);

    while(test != nullptr)
    {
        std::cout << test->val << "\n";
        test= test->next;
    } 

}


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