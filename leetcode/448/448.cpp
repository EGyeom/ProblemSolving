/* Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int len = nums.size();
        vector<int> ans;
        vector<int> count_vector(len,0);
        for(int i =0; i < len; i++)
        {
            count_vector[nums[i]-1]++;
        }

        for(int i =0; i < len; i++)
        {
            if(count_vector[i] == 0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};