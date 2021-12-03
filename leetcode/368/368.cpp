#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(size,1), origin(size,-1);
        int max_val = 0;
        int max_index = 0;
        for(int i =1; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[j]+1 > dp[i])
                    {
                        dp[i] = dp[j]+1;
                        origin[i] = j;
                    }
                }
            }

            if(max_val < dp[i])
            {
                max_val = dp[i];
                max_index = i;
            }
        }
        vector<int> ans;
        while(max_index != -1)
        {
            ans.push_back(nums[max_index]);
            max_index = origin[max_index];
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> v = {5,9,18,54,108,540,90,180,360,720};
    vector<int> ans = s.largestDivisibleSubset(v);

    for(int i =0; i < ans.size(); i++)
    {
        std::cout << ans[i] <<"\n";
    }
}

// Input
// [5,9,18,54,108,540,90,180,360,720]
// Output
// [5,90,180,360,720]
// Expected
// [9,18,90,180,360,720]