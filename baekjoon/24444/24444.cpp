#include <bits/stdc++.h>
using namespace std;

int n,m,r;
vector<vector<int>> arr(100001,vector<int>());
vector<int> visited(100001,0);
void bfs(int r)
{
    queue<int> q;
    int gOrder = 1;
    q.push(r);
    visited[r] = gOrder++;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int& iter : arr[temp])
        {
            if(visited[iter] == 0)
            {
                q.push(iter);
                visited[iter] = gOrder++;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n,&m,&r);
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    for(vector<int>& iter : arr)
    {
        sort(iter.begin(), iter.end(), greater<int>());
    }
    bfs(r);

    for(int i = 1; i <= n; i++)
    {
        printf("%d\n", visited[i]);
    }
}