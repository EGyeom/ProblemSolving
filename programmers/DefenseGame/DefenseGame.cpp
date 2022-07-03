#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int enemySize = enemy.size();
    if(k >= enemySize)
        return enemySize;
    
    priority_queue<int> pq;
    
    int enemySum = 0;
    for(int i = 0; i < enemySize; i++)
    {
        pq.push(enemy[i]);

        enemySum += enemy[i];
        if(enemySum > n)
        {
            if(k <= 0) break;
            enemySum -= pq.top();
            pq.pop();
            k--;
        }
        answer++;
    }
    return answer;
}

int main()
{

}