#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> isvisited;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    isvisited = vector<int>(n,0);
    int count = 0;
    for(int i =0; i < n; i++)
    {
        if(isvisited[i]) continue;
        count++;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            if(isvisited[index]) continue;
            isvisited[index] = count;
            for(int j =0; j < n; j++)
            {
                if(i == j || isvisited[j]) continue;
                if(computers[index][j] == 1) q.push(j);
            }
        }
    }

    return answer = count;
}