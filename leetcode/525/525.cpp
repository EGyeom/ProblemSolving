#include <bits/stdc++.h>
using namespace std;

// First answer
/* 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int max_length = 0;
        int numSize = nums.size();
        unordered_map<int,int> m;
        for(int i =0; i < numSize; i++)
        {
            sum += nums[i] ? 1 : -1;
            if(sum == 0) max_length = max_length > i+1 ? max_length : i+1;
            else if(m.find(sum) != m.end())
            {
                max_length = max_length > i - m[sum] ? max_length : i - m[sum];
            }
            else m[sum] = i;
        }

        return max_length;
    }
};
 */

// Second answer

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int max_length = 0;
        int numSize = nums.size();
        unordered_map<int,int> m{{0,-1}};
        for(int i =0; i < numSize; i++)
        {
            sum += nums[i] ? 1 : -1;
            if(m.find(sum) != m.end())
            {
                max_length = max_length > i - m[sum] ? max_length : i - m[sum];
            }
            else m[sum] = i;
        }

        return max_length;
    }
};


int main()
{
    
}