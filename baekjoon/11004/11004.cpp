#include <bits/stdc++.h>
#define abs(X) ((X)) < 0 ? (-(X)) : ((X))
using namespace std;
long long arr[5000000];

int partitioning(long long *arr, int left, int right, int k)
{
    long long pivot = 0;
    if(abs(k - left) < abs(k-right))
    {
        pivot = arr[left];
    }
    else pivot = arr[right];
    
    int l =0, r = 0;
    while(r < right)
    {
        if(arr[r] <= pivot)
        {
            swap(arr[l], arr[r]);
            l++; r++;
        }
        else
        {
            r++;
        }
    }
    swap(arr[l], arr[r]);
    return l;
}

long long nth_value(long long *arr, int left, int right, int k)
{
    int pivot = partitioning(arr, left, right, k);
    if(pivot < k)
    {
        return nth_value(arr,pivot+1, right,k);
    }
    else if(pivot > k)
    {
        return nth_value(arr,left,pivot -1,k);
    }
    else
    {
        return arr[pivot];
    }
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    for(int i =0; i < n ; i++)
    {
        scanf("%lld",&arr[i]);
    }
    printf("%lld\n",nth_value(arr,0,n-1,k-1));
}