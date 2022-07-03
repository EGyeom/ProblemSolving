#include <bits/stdc++.h>
using namespace std;

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> isVisited;
int gCount = 0;

void dfs(int cur)
{
    gCount++;
    if (v[cur].empty())
        return;

    for (const int& nxt : v[cur])
    {
        if (isVisited[nxt] == true) continue;
        isVisited[nxt] = true;
        dfs(nxt);
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 102;
    for (int i = 0; i < n-1; i++)
    {
        v.clear();
        v.resize(101, vector<int>());
        isVisited.clear();
        isVisited.resize(101, false);
        gCount = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (i == j) continue;
            v[wires[j][0]].push_back(wires[j][1]);
            v[wires[j][1]].push_back(wires[j][0]);
        }
        isVisited[1] = true;
        dfs(1);
        answer = min(answer, abs((n - gCount) - gCount));
        if(answer == 0 ) break;
    }

    return answer;
}

int main()
{

}