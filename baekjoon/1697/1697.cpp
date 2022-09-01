#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<bool> checked;
void bfs(int start, int target)
{
    queue<pair<int,int>> q;
    checked[start] = true;
    q.push({start*2,1});
    q.push({start+1,1});
    q.push({start-1,1});
    while(!q.empty())
    {
        int first = q.front().first;
        int second = q.front().second;
        cout << first << " " << second << "\n";
        q.pop();
        if(checked[first]) continue;
        checked[first] = true;
        if(v[first] == 0)
        {
            v[first] = second;
        } 
        else if(second > v[first]) continue;
        else if(first > target)
        {
            int tmp = first - target + second;
            v[first] = min(tmp, v[first]);
            continue;
        }
        q.push({first*2,second+1});
        q.push({first+1,second+1});
        q.push({first-1,second+1});
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    v = move(vector<int>(100001,0));
    checked = move(vector<bool>(100001,false));
    bfs(n,k);
    cout << v[k] << "\n";
}