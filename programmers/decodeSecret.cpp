#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isValid(const vector<vector<int>>& q, const vector<int>& ans, const vector<int>& cur)
{
    int qSize = q.size();
    for(int m = 0; m < qSize; m++)
    {
        int cnt =0;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(cur[i] == q[m][j])
                {
                    cnt++;
                    break;
                }
            }
        }
        if(cnt != ans[m])
            return false;
    }
    return true;
}

void dfs(int n, const vector<vector<int>>& q, const vector<int>& ans, vector<int>& cur, int& answer, int idx)
{
    if(cur.size() == 5)
    {
        if(isValid(q, ans, cur))
        {
            answer++;
        }
        return;
    }
    for(int i = idx; i <= n; i++) // 1~n까지만
    {
        cur.push_back(i);
        dfs(n, q, ans, cur, answer, i+1);
        cur.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> cur;
    dfs(n, q, ans, cur, answer, 1);
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> check(n+1, 0);
    fill(check.end()-5, check.end(), 1);

    do
    {
        bool isFind = true;
        for(int i = 0; i < q.size(); i++)
        {   
            if(ans[i] != check[q[i][0]] + check[q[i][1]] + check[q[i][2]] + check[q[i][3]] + check[q[i][4]])
            {
                isFind = false;
                break;
            }
        }
        if(isFind) answer++;
    } while (next_permutation(check.begin()+1, check.end()));

    return answer;
}
