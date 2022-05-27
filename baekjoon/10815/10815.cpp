#include <bits/stdc++.h>
using namespace std;

int BinarySearch(const vector<int>& nums,const int& num, const int& start, const int& end)
{
    if(start > end) return 0;
    int middle = (start+end) % 2 ==0 ? (start+end) /2 : (start+end) /2 + 1;
    if(nums[middle] == num || nums[start] == num || nums[end] == num)
    {
        return 1;
    }
    else if(nums[middle] < num)
    {
        return BinarySearch(nums,num,middle+1,end);
    }
    else
    {
        return BinarySearch(nums,num,start,middle-1);
    }
}

int main()
{
    /* unordered_map<int,int> um;
    vector<int> mNums;
    int n,m;

    scanf("%d", &n);
    for(int i =0; i< n; i++)
    {
        int temp;
        scanf("%d", &temp);
        um.insert({temp, 1});
    }

    scanf("%d", &m);
    for(int i =0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(um.find(temp) != um.end())
        {
            // mNums.push_back(1);
            printf("1 ");
        }
        else
        {
            // mNums.push_back(0);
            printf("0 ");
        }
    } */
    int n,m;
    scanf("%d", &n);
    vector<int> nNums(n,0);
    for(int i =0; i <n; i++)
    {
        scanf("%d",&nNums[i]);
    }
    
    sort(nNums.begin(), nNums.end());
    scanf("%d", &m);
    for(int i =0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        printf("%d ",BinarySearch(nNums,temp,0,n-1));
    }
}