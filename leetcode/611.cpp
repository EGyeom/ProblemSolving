class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int answer = 0;
        for(int i = 0; i < n-2; i++)
        {
            int k = i+2;
            for(int j = i+1; j < n-1 && nums[j] != 0; j++)
            {
                while(k < n && nums[i] + nums[j] > nums[k]) k++;
                if(k > j)
                    answer += k - j - 1;
            }
        }

        return answer;
    }
};
