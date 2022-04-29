#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 0)
    {
        printf("0\n");
        return 0;
    }

    vector<int> v;
    while(n != 0)
    {
        if(n < 0)
        {
            v.push_back(-n%-2);            
            n = (n-1)/(-2);
        }
        else
        {
            v.push_back(n%-2);
            n = n / -2;
        }
    }
    while(!v.empty())
    {
        printf("%d",v.back());
        v.pop_back();
    }
    printf("\n");
}