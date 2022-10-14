#include <bits/stdc++.h>
using namespace std;


#define INPUTMAX 32000

int input;
stack<int> st;
vector<int> isVisited(INPUTMAX,0);
vector<int> edgeInfo[INPUTMAX];

void dfs(int curr)
{
    isVisited[curr] = true;
    for(int& iter : edgeInfo[curr])
    {
        if(isVisited[iter] == false)
        {
            dfs(iter);
        }
    }
    st.push(curr);
}

void topologySort_dfs()
{    
    for(int i = 1; i <= input; i++)
    {
        if(isVisited[i] == false)
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        edgeInfo[a].push_back(b);
    }

    input = n;

    topologySort_dfs();
    while(st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}