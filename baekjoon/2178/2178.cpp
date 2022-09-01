#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v= {1,2,5,6,4,3};
    list<int> l = v;
    
}

/* vector<string> arr(101);

int dp[100][100];
int n,m;

void dfs(int i, int j)
{
    arr[i][j] = 0;

    if(arr[i-1][j] == 0 && arr[i+1][j] == 0 && arr[i][j-1] == 0 && arr[i][j+1] == 0)
    {
        return;
    }
    if(arr[i-1][j] == 1)
    {
        dfs(i-1,j);
    }
    if(arr[i+1][j] == 1)
    {
        dfs(i+1,j);
    }
    if(arr[i][j-1] == 1)
    {
        dfs(i,j-1);
    }
    if(arr[i][j+1] == 1)
    {
        dfs(i,j+1);
    }

}

int main()
{
    cin >> n >> m;
    for(int i =0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0,0);
} */