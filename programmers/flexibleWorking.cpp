#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    for(int j = 0; j < n; j++)
    {
        bool isPass = true;
        int timeLimit = schedules[j] % 100 >= 50 ? schedules[j] + 50 : schedules[j] + 10;

        for(int i = 0; i < 7; i++)
        {
            if((i+startday-1) % 7 >= 5)
                continue;

            if(timeLimit < timelogs[j][i])
            {
                isPass = false;
                break;
            }
        }
        if(isPass != false)
            answer++;
    }

    return answer;
}