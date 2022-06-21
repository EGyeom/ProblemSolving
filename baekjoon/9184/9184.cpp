#include <bits/stdc++.h>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0) return dp[0][0][0];
    if(a > 20 || b > 20 || c > 20)
    {
        if(dp[20][20][20]) return dp[20][20][20];
        else return w(20,20,20);
    }
    if(a < b && b < c)
    {
        if(dp[a][b][c]) return dp[a][b][c];
        else return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    if(dp[a][b][c]) return dp[a][b][c];
    else return dp[a][b][c] =  w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main()
{
    dp[0][0][0] = 1;
    while(1)
    {
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a,b,c,w(a,b,c));
    }

}