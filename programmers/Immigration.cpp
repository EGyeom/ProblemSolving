#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long l = 1;
    long long r = (long long)(*max_element(times.begin(), times.end())) * n; //자료형 조심
    long long answer = r;
    while(l <= r)
    {
        long long mid = (l + r) / 2;
        long long total = 0;
        for(int& it : times)
        {
            total += (mid / it); 
        }   
        if(total >= n) // total >= n 모든 인원 검사 가능 (시간이 충분)
        {
            r = mid - 1;
            answer = min(answer, mid);
        }
        else l = mid + 1;
    }
    
    return answer;
}
