#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INPUTMAX 32001
int input;
vector<int> edgeInfo[INPUTMAX],inDegree(INPUTMAX,0);

void topologySort(vector<int> indegree)
{
    queue<int> q;
    
    for(int i = 1; i <= input; i++)
    {
        if(inDegree[i] == 0)
            q.push(i);
    }

    while(q.empty() == false)
    {   
        int front = q.front();
        q.pop();
        cout << front << " ";
        for(int& edge : edgeInfo[front])
        {
            if(--inDegree[edge] == 0)
                q.push(edge);
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
        inDegree[b]++;
    }

    input = n;
    topologySort(inDegree);
}