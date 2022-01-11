class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numSize = nums.size();
        int i =0;
        while(i < numSize)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                numSize--;
            }
            else
            {
                i++;
            }
        }
        return numSize;
    }
};