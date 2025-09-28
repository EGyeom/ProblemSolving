class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int answer = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = n-1; i >= 2; i--)
        {
            if(nums[i] < nums[i-1] + nums[i-2])
                return nums[i] + nums[i-1] + nums[i-2];
        }

        return answer;
    }
};
