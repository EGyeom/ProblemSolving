class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ = nums[0];
        int min_ = nums[0];
        int ans = nums[0];
        for (int i = 1 ; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                swap(max_,min_);
            }
            
            max_ = max(nums[i], max_*nums[i]);
            min_ = min(nums[i], min_*nums[i]);
        
            ans = max(max_, ans);
        }
        return ans;
    }
};