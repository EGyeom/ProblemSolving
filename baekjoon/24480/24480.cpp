#include <bits/stdc++.h>
using namespace std;

int n,m,r;
int gOrder = 1;
vector<int> visited(100001,0);
vector<vector<int>> arr(100001,vector<int>());

void dfs(int index)
{
    
    visited[index] = gOrder++;

    for(int& val : arr[index])
    {
        if(visited[val] != 0) continue;
        dfs(val);
    }
}

int main()
{
    scanf("%d %d %d", &n,&m,&r);

    for(int i =1; i <= m; i++)
    {
        int u,v;
        scanf("%d %d", &u,&v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for(vector<int>& iter : arr)
    {
        sort(iter.begin(), iter.end(), greater<int>());
    }
    
    dfs(r);

    for(int i =1; i <= n; i++)
    {
        printf("%d\n", visited[i]);
    }
}