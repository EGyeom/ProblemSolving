#include <bits/stdc++.h>
using namespace std;

int n;
int ret = INT_MAX;
int abilities[21][21];
bool visited[21];

void dfs(int num, int pos)
{
    if(num == n /2)
    {
        int stark = 0, link = 0;
        for(int i = 1 ; i <= n; i++)
        {
            for(int j = 1; j <=n; j++)
            {
                if(visited[i] && visited[j]) stark += (abilities[i][j]);
                else if(!visited[i] && !visited[j]) link += (abilities[i][j]);
            }
        }
        ret = min(ret, abs(stark-link));
        return ;
    }
    for(int i = pos; i <= n; i++)
    {
        visited[i] = true;
        dfs(num+1,i+1);
        visited[i] = false;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i =1; i <= n ;i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &abilities[i][j]);
        }
    }
    dfs(0,1);
    printf("%d\n", ret);
}