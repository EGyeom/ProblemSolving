#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int worst_count = 0;
    int zero_count = 0;
    for(int i =0; i < 6; i++)
    {
        if(lottos[i] == 0)
        {
            zero_count++;
            continue;
        }
        for(int j =0; j < 6; j++)
        {
            if(lottos[i] == win_nums[j])
            {
                worst_count++;
                break;
            }
        }
    }
    answer.push_back(7-worst_count-zero_count >= 6 ? 6 : 7-worst_count-zero_count);
    answer.push_back(7-worst_count >= 6 ? 6 : 7-worst_count);
    return answer;
}
int main()
{
    vector<int> ans = solution({1,2,3,4,5,6}, {7,8,9,10,11,12});
    for(auto iter : ans)
    {
        cout << iter << "\n";
    }
}