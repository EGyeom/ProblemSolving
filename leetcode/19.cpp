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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head)
            return nullptr;

        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        ListNode* newHead = new ListNode(0, head);
        int idx = 0;
        temp = newHead;
        
        while(temp)
        {
            if(idx == count-n)
            {
                ListNode* tempNode = temp->next;
                if(tempNode)
                    temp->next = tempNode->next;
                break;
            }
            idx++;
            temp = temp->next;
        }

        return newHead->next;
    }
};