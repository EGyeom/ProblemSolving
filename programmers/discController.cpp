#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)
    {
        return a.second > b.second;
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) -> bool
         {
             return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; 
    
    int cnt = 0;
    int jobSize = jobs.size();
    int i = 0;
    while(true)
    {
        if(i >= jobSize && pq.empty())
            break;
        
        while(i < jobSize && jobs[i][0] <= cnt)
        {
            pq.push({jobs[i][0], jobs[i][1]});
            i++;
        }
        
        if(!pq.empty())
        {
            answer += cnt + pq.top().second - pq.top().first;
            cnt += pq.top().second;
            pq.pop();
        }
        else
        {
            cnt = jobs[i][0];
        }
        
    }
    
    return answer/jobSize;
}
