#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(1001,vector<int>());
vector<bool> visited(1001,0);

void dfs(int num)
{
    printf("%d ", num);
    visited[num] = true;
    for(int& iter : arr[num])
    {
        if(!visited[iter]) dfs(iter);
    }
}

void bfs(int num)
{
    queue<int> q;
    q.push(num);
    visited[num] = true;
    printf("%d ", num);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int& iter : arr[temp])
        {
            if(!visited[iter])
            {
                printf("%d ", iter);
                q.push(iter);
                visited[iter] = true;
            }
        }
    }
}

int main()
{
    int n,m,r;
    scanf("%d %d %d", &n, &m, &r);

    for(int i = 1; i<= m ;i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for(vector<int>& iter : arr)
    {
        sort(iter.begin(), iter.end());
    }

    dfs(r);
    printf("\n");
    for(int i =0; i <= 1000; i++)
    {
        visited[i] = false;
    }
    bfs(r);
}