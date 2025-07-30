class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        for(int num : nums) maxVal = maxVal < num ? num : maxVal;
        int len = 0;
        int cur_len = 0;
        for(int num : nums)
        {
            if(num == maxVal) cur_len++;
            else cur_len = 0;

            len = max(len, cur_len);
        }
        return len;
    }
};