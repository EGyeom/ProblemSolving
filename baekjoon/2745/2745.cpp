#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    int B;
    cin >> N >> B;
    long long num = 0;
    int index = 0;
    while(index < N.size())
    {
        num *= B;
        if(N[index] >= 'A')
        {
            num += (N[index] - 'A') + 10;
        }
        else
        {
            num += N[index] - '0'; 
        }
        index++;
    }

    printf("%lld\n", num);
}