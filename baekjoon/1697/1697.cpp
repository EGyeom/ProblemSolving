#include <bits/stdc++.h>
using namespace std;

int min_ = INT_MAX;
int arr[100001];

void func(int initNum, int num, int target, int count, int cal)
{
    printf("%d %d %d %d %d\n", initNum, num, target, count, arr[num]);
    if(arr[target] != 0 && arr[target] <= count) return;
    if(arr[num] == 0) arr[num] = count;
    else if(count < arr[num]) arr[num] = count;
    else return ;

    if(num == target)
    {
        min_ = count < min_ ? count : min_;
        return;
    }
    else if(num <= 0 || num == initNum) return;
    if(num < target)
    {
        func(initNum,num*2,target,count+1,3);
    
        if(cal & 1) func(initNum,num+1,target,count+1,1);

        if(cal & 2) func(initNum,num-1,target,count+1,2);
    }
    else
    {
        min_ = count + num - target;
        arr[target] = min_;
    } 
}

int main()
{
    int n, k;
    int count_ = 1;
    scanf("%d %d", &n, &k);
    func(n,n*2,k,count_,3);
    func(n,n+1,k,count_,1);
    func(n,n-1,k,count_,2);
    printf("%d\n", min_);
}