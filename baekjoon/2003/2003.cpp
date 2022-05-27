#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int count_ = 0;
    int n,m;
    scanf("%d %d", &n, &m);

    vector<int> v(n,0);
    for(int i =0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    int start =0, end = 0;

    int sum = 0;
    while(end <= n)
    {
        if(sum == m)
        {
            count_++;
            sum -= v[start++];
        }
        else if(sum > m)
        {
            sum -= v[start++];
        }
        else
        {
            sum += v[end++];
        }
    }
    printf("%d\n", count_);
}