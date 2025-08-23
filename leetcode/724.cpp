class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            if(sum == nums[n-1] - nums[i]){
                return i;
            }
            sum = nums[i];
        }
        return -1;
    }
};
