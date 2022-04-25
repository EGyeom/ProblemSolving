#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    int B;
    scanf("%lld %d", &N, &B);
    vector<char> ans;
    while(N != 0)
    {
        int mod = N % B;
        if(mod < 10)
        {
            ans.push_back('0'+ mod);
        }
        else
        {
            ans.push_back('A'+ (mod-10));
        }
        N /= B;
    }

    for(int i = ans.size()-1; i >= 0; i--)
    {
        printf("%c",ans[i]);
    }
    printf("\n");
}