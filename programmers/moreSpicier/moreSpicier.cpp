#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());   
    
    int top = pq.top();
    pq.pop();
    while(top < K && !pq.empty())
    {
        answer++;
        top += (pq.top() * 2);
        pq.pop();
        pq.push(top);
        top = pq.top();
        pq.pop();
    }
    if(top < K)
        answer = -1;
    return answer;
}

int main()
{

}