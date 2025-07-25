class Solution {
public:
    int maxSum(vector<int>& nums) {

        set<int> s(nums.begin(), nums.end());
        int maxNum = -101;
        int maxSum = 0;
        for(int num : s)
        {
            if(num > maxNum) maxNum = num;
        }

        if(maxNum < 0) return maxNum;
        else
        {
            for(int num : s)
            {
                if(num < 0)
                    s.erase(num);
                else maxSum += num;
            }
        }

        return maxSum;
    }
};