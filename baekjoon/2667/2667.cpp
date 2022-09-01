#include <bits/stdc++.h>
using namespace std;

vector<string> m(27,string("000000000000000000000000000"));
vector<int> ret;
// vector<vector<bool>> isvisied(25,vector<bool>(25));
int num = 0;

void dfs(int i, int j)
{
    num++;
    m[i][j] = '0';

    if(m[i-1][j] == '0' && m[i+1][j] == '0' && m[i][j-1] == '0' && m[i][j+1] == '0')
    {
        return;
    }
    if(m[i-1][j] == '1')
    {
        dfs(i-1,j);
    }
    if(m[i+1][j] == '1')
    {
        dfs(i+1,j);
    }
    if(m[i][j-1] == '1')
    {
        dfs(i,j-1);
    }
    if(m[i][j+1] == '1')
    {
        dfs(i,j+1);
    }

}


int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 1; j <= n; j++)
        {
            m[i][j] = temp[j-1];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(m[i][j] == '0') continue;
            num = 0;
            dfs(i,j);
            ret.push_back(num);
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for(int i =0; i < ret.size(); i++)
    {
        cout << ret[i] << "\n";
    }
}