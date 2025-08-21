#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    vector<vector<int>> v((n-1/w));

    for(int i = 1; i <= n; i++)
    {
        if( (i-1)/w % 2 == 0 )
            v[(i-1)%w].push_back(i);
        else v[w-(i-1)%w-1].push_back(i);
    }

    for(int i = 0; i < v.size(); i++)
    {
        answer = 1;
        while(!v[i].empty())
        {
            if(v[i].back() != num)
            {
                answer++;
                v[i].pop_back();
            }

            else break;
        }
        if(!v[i].empty())
            break;
    }

    return answer;
}