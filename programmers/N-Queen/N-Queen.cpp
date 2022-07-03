#include <string>
#include <vector>

using namespace std;

vector<int> rows(12,0);
int answer;

bool isPossible(int y)
{
    for(int i = 0; i < y; i++)
    {
        if((rows[y] == rows[i]) || (abs(rows[y] - rows[i]) == abs(y - i)))
            return false;
    }

    return true;
}

void dfs(int num, int n)
{
    if(num == n)
    {
        answer++;
        return;
    }
    for(int i =0; i < n; i++)
    {
        rows[num] = i;
        if(isPossible(num))
            dfs(num+1, n);
    }
}

int solution(int n) {
    dfs(0, n);
    return answer;
}