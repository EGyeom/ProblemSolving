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

bool compare(int*& a, int*& b)
{
    return a[0] < b[0];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =1; i <=n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    
    sort(arr+1, arr+n+1);

    for(int i =1; i <=n; i++)
    {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

}