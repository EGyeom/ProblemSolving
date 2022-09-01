#include <bits/stdc++.h>
using namespace std;

int ret= -1;
vector<vector<int>> v(101,vector<int>());
vector<bool> visited(101);

void dfs(int num)
{
    visited[num] = true;
    ret++;
    for(int& iter : v[num])
    {
        if(visited[iter]) continue;
        dfs(iter);
    }
}

int main()
{
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i<=m; i++)
    {
        int com1,com2;
        scanf("%d %d", &com1, &com2);
        v[com1].push_back(com2);
        v[com2].push_back(com1);
    }
    
    dfs(1);
    printf("%d\n", ret);
}