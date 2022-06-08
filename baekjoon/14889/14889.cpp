#include <bits/stdc++.h>
using namespace std;

int ret = INT_MAX;
int n;
int teamCount = 0;
vector<vector<int>> v;
vector<bool> visited;
vector<int> t_stark;

void dfs(int pos)
{
    if(pos >= n) return;
    if((teamCount == n/2))
    {
        for(int i =0; i < teamCount; i++)
        {
            
        }
        return;
    }
    for(int i =pos+1; i <n; i++)
    {
        teamCount++;
        t_stark.push_back(i);
        dfs(pos+1);
        t_stark.pop_back();
        teamCount--;
    }

}


int main()
{
    scanf("%d", &n);
    
    for(int i =0; i < n; i++)
    {
        vector<int> vTemp;
        for(int j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);
            vTemp.push_back(temp);
        }
        vTemp.clear();
    }
    t_stark.push_back(0);
    teamCount = 1;
    dfs(0);
    printf("%d\n", ret);
}