vector<bool> isVisited;

void dfs(vector<vector<int>>& answer, vector<vector<int>>& graph, int cur, vector<int>& temp)
{
    if(cur == graph.size() -1)
    {
        answer.push_back(temp);
        return;
    }
    for(int next : graph[cur])
    {
        if(isVisited[next]) continue;
        isVisited[next] = true;
        temp.push_back(next);
        dfs(answer,graph,next,temp);
        temp.pop_back();
        isVisited[next] = false;
    }
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        isVisited.resize(graph.size(), 0);
        vector<vector<int>> answer;
        vector<int> temp;
        temp.push_back(0);
        dfs(answer, graph, 0, temp);
        return answer;
    }
};