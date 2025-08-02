class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        int n = nums.size();
        for(int i = 0; i < n-3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j < n-2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k < l)
                {
                    long long fourSum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(fourSum > target)
                    {
                        l--;
                    }
                    else if(fourSum < target)
                    {
                        k++;
                    }
                    else
                    {
                        answer.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }
                }
            }
        }
        return answer;
    }
};
