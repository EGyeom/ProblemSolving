class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int r = n-1;
        int l = r -1;
        while(l >= 0)
        {        
            //목록 오른쪽에서부터 첫번째로 감소하는 숫자 찾기
            if(nums[l] < nums[r])
            {
                int smallest = 101;
                int smallestIdx = 0;
                // 첫번째로 감소하는 요소보다 큰, 오른쪽에서 가장 작은 숫자 찾기
                for(int i = l+1; i < n; i++)
                {
                    if(nums[i] > nums[l])
                    {
                        if(smallest > nums[i])
                        {
                            smallestIdx = i;
                        }
                    }
                }
                // 두 숫자 스왑
                swap(nums[smallestIdx], nums[l]);
                break;
            }
            else
            {
                l--;
                r--;
            } 
        }
        l = l+1;
        r = n-1;
        while(l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        return;
    }
};


class Solution {
public:
    void solve(vector<int>& nums){
        int n = nums.size();
        int i = n - 2;

        // first finding pivot index

        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        //find the j that is must larger than the i

        if(i>=0){
            int j = n-1;
            while(nums[i] >= nums[j]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        
        //step 3: reveserse the array
        reverse(nums.begin()+i+1,nums.end());
    }
    void nextPermutation(vector<int>& nums) {
        solve(nums);
    }
};