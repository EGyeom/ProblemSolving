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
    int getDecimalValue(ListNode* head) {
        int length = 0;
        vector<int> v;
        int ans = 0;
        while(head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
            length++;
        }
        printf("%d\n", length);
        for(int i = length-1; i >= 0; i--)
        {
            ans += v[i]*pow(2,length - i - 1);   
        }
        
        return ans;
    }
};

/* class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head != nullptr)
        {
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        return ans;
    }
}; */