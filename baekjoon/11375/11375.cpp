#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> visited(1000,0);
int N, M;
int ret;
int count_work;
void dfs(int pos)
{
    if(pos == N)
    {
        ret = ret < count_work ?  count_work : ret;
        return;
    }
    for(int i = 0; i < v[pos].size(); i++)
    {
        if(visited[v[pos][i]] == true)
        {
            dfs(pos+1);
            continue;
        }
        visited[v[pos][i]] = true;
        count_work++;
        dfs(pos+1);
        count_work--;
        visited[v[pos][i]] = false;
    }
}

int main()
{
    scanf("%d %d", &N,&M);
    for(int i =0; i < N; i++)
    {
        vector<int> vTemp;
        int work;
        scanf("%d", &work);
        for(int j = 0; j < work; j++)
        {
            int temp;
            scanf("%d", &temp);
            vTemp.push_back(temp);
        }
        v.push_back(vTemp);
        vTemp.clear();
    }
    dfs(0);
    printf("%d\n", ret);
}