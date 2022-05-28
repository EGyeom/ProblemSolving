#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<pair<int,int>> v;
    int N;
    int ret;
    scanf("%d", &N);
    vector<int> visited(N+1,0);
    for(int i =0; i < N; i++)
    {
        int t, pay;
        scanf("%d %d", &t, &pay);
        v.push_back({t,pay});
    }

    for(int i = N-1; i >= 0; i--)
    {
        int deadline = i + v[i].first;
        if(deadline > N)
        {
            visited[i] = visited[i+1];
        }
        else
        {
            visited[i] = max(visited[i+1], visited[deadline] + v[i].second);
        }
    }
    printf("%d\n", visited[0]);
}