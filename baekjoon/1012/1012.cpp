#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(52,vector<int>(52));

int num = 0;

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
    int t;
    scanf("%d", &t);
    for(t; t > 0; t--)
    {
        int m,n,k;
        num = 0;
        cin >> m >> n >> k;
        for(k; k > 0; k--)
        {
            int x,y;
            cin >> y >> x;
            arr[y+1][x+1] = 1;
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(arr[i][j] == 0) continue;
                num++;
                dfs(i,j);
            }
        }
        cout << num << "\n";
    }
}