#include <string>
#include <vector>

using namespace std;

vector<bool> isVisited;
int dungeonSize;
int maxCount;
void dfs(vector<vector<int>>& dungeons, int k, int cur_visit)
{
    maxCount = max(maxCount, cur_visit);
    for(int i =0; i < dungeonSize; i++)
    {
        if(isVisited[i] || k < dungeons[i][0] || (k - dungeons[i][1]) < 0) continue;
        isVisited[i] = true;
        dfs(dungeons, k - dungeons[i][1], cur_visit+1);
        isVisited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeonSize = dungeons.size();
    isVisited = vector<bool>(dungeonSize,0);

    dfs(dungeons,k,0);

    return maxCount;
}