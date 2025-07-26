class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numSize = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < numSize; i++)
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;

            int j = i + 1;
            int k = numSize - 1;

            while(j < k)
            {
                int threeSum = nums[i] + nums[j] + nums[k];

                if(threeSum > 0)
                {
                    k--;
                }
                else if (threeSum < 0)
                {
                    j++;
                }
                else
                {
                    answer.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j] == nums[j-1] && j < k) j++;
                }

            }
        }

        return answer;
    }
};