#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b)
{
    if(a % b == 0) return b;
    return GCD(b, a%b);
}

int main()
{
        long long a , b;
        scanf("%lld %lld", &a, &b);
        if(a < b)
        {
            long long temp = a;
            a = b;
            b = temp;
        }
        // int gcdVal = GCD(a, b);
        for(int i =0; i < GCD(a,b); i++)
        {
            printf("1");
        }
        printf("\n");
}