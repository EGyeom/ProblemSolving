#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long arr[4] = {0,};
    for(int i =0; i <4; i++)
    {
        scanf("%d", &arr[i]);
    }
    int temp = arr[1];
    while(arr[1] != 0)
    {
        arr[0] *= 10;
        arr[1] /= 10;
    }
    arr[0] += temp;

    temp = arr[3];
    while(arr[3] != 0)
    {
        arr[2] *= 10;
        arr[3] /= 10;
    }
    arr[2] += temp;

    printf("%lld\n", arr[0] + arr[2]);
}