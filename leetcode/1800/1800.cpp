#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int numSize=nums.size();
        if(numSize == 0) return 0;
        int max = 0;
        int temp = nums[0];
        for(int i =1; i < numSize; i++)
        {
            if(nums[i-1] < nums[i])
            {
                temp += nums[i];
            }
            else
            {
                if(max < temp) max = temp;
                temp = nums[i];
            }
        }
        if(max < temp) max = temp;
        return max;
    }
};


int main()
{   
    Solution s;
    vector<int> v = {10,20,30,5,10,50};
    printf("%d\n", s.maxAscendingSum(v));
}