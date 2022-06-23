#include <bits/stdc++.h>
using namespace std;
/* 예제 입력 1 
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

예제 출력 1 
3 */
int dp[101];
vector<vector<int>> v(100,vector<int>(2,0));

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =0; i <n; i++)
    {
        scanf("%d %d", &v[i][0], &v[i][1]);
        dp[i] = 1;
    }
    
    sort(v.begin(), v.begin()+n);

    int ret = 0;
    for(int i =1; i <n; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(v[i][1] > v[j][1] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] +1;
                if(ret < dp[i]) ret = dp[i];
            }
        }
    }
    printf("%d\n", n - ret);
}