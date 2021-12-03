#include <cstdio>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left= 0, right = size-1;
        int middle =0;
        while(left <= right)
        {
            middle = (left+right)/2;

            if(target < nums[middle])
            {
                right = middle - 1;
            }
            else if(target > nums[middle])
            {
                left = middle + 1;
            }
            else return middle;
        }
        if(target < nums[middle])
        {
            return middle;
        }
        else return middle+1;
}

int main()
{
    vector<int> v = {1,3,5,6};
    int index = searchInsert(v,0);

    printf("%d\n", index);
}