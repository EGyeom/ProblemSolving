#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>> pq;
vector<vector<pair<int,int>>> cities;
vector<int> vTrace;
vector<int> d;

void dijkstra(int start, int end)
{
    d[start] = 0;
    pq.push({0,start});

    while(!pq.empty())
    {
        int city = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(cost > d[city]) continue;
        for(int i = 0; i < cities[city].size(); i++)
        {
            int nextCity = cities[city][i].first;
            int nextCost = cities[city][i].second + cost;

            if(d[nextCity] > nextCost)
            {
                d[nextCity] = nextCost;
                vTrace[nextCity] = city;
                pq.push({-nextCost,nextCity});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    cities.reserve(n+1);
    vTrace.reserve(n+1);
    d.resize(n+1,INT_MAX);

    for(int i =0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        cities[start].push_back(make_pair(end,cost));
    }
    
    int start, end;
    cin >> start >> end;

    dijkstra(start,end);
    stack<int> path;
    int bt = vTrace[end];
    path.push(end);
    while(bt != 0)
    {
        path.push(bt);
        bt = vTrace[bt];        
    }

    printf("%d\n", d[end]);
    printf("%d\n", path.size());
    while(path.empty()==false)
    {
        printf("%d ", path.top());
        path.pop();
    }
}