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
// revised version
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int minVal = 101;
        int r = n-2;
        while(r > -1 && nums[r] >= nums[r+1]) r--; 

        if(r > -1)
        {
            for(int i = n-1; i > r; i--)
            {
                if(nums[r] < nums[i])
                {
                    if(minVal > nums[i])
                    {
                        minVal = nums[i];
                        idx = i;
                    }
                }
            }
            swap(nums[idx], nums[r]);
        }

        reverse(nums.begin()+r+1, nums.end());
    }
};
