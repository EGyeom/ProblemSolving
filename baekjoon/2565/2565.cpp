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
int arr[101][2];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =1; i <=n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for(int i = 2; i <=n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(arr[i][0] > arr[j][0] && arr[i][1] < arr[j][1])
            {
                dp[j]++;
            }
        }
    }

    for(int i =1; i <=n; i++)
    {
        printf("%d\n", dp[i]);
    }
}