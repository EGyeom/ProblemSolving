#include <bits/stdc++.h>
using namespace std;

char ret[16];
int n,m;
bool isvisited[9];

void dfs(int num, int t)
{
    if(num == m)
    {
        printf("%s\n", ret);
        return;
    }
    for(int i = t; i < n; i++)
    {
            ret[num] = i + '1';
            dfs(num+2, i);
    }
}

int main()
{
    scanf("%d %d", &n, &m );
    memset(ret,' ',sizeof(ret));
    m += m;
    ret[m-1] = 0;
    dfs(0,0);
}