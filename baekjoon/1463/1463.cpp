#include <bits/stdc++.h>

int dp[100001];

int findNum(int num)
{
    if(num == 1) return 0;
    dp[1] = 0;
    for(int i =2; i <= num; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i % 3 == 0) dp[i] = dp[i] < (dp[i/3] +1) ? dp[i] : (dp[i/3] +1);
        if(i % 2 == 0) dp[i] = dp[i] < (dp[i/2] +1) ? dp[i] : (dp[i/2] +1);
    }
    return dp[num];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", findNum(n));
}

/* 
#include <cstdio>
int f(int x) {
	if (x <2) { return 0; }
	int v1 = f(x/3) + x % 3 + 1;
	int v2 = f(x/2)+ x % 2 + 1;
	return v1<v2?v1:v2;
}
int main() {
	int x;
	scanf("%d", &x);
	printf("%d",f(x));
} */