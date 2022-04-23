#include <bits/stdc++.h>
using namespace std;
/* 
국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 
(단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
 */
unordered_map<string,vector<int>> m;

int compare(pair<string,vector<int>> left, pair<string,vector<int>> right)
{
    if(left.second[0] > right.second[0])
    {
        return 1;
    }
    else if(left.second[0] == right.second[0])
    {
        if(left.second[1] < right.second[1])
        {
            return 1;
        }
        else if(left.second[1] == right.second[1])
        {
            if(left.second[2] > right.second[2])
            {
                return 1;
            }
            else if (left.second[2] == right.second[2])
            {
                return left.first < right.first; 
            }
            else return 0;
        } 
        else return 0;
    }
    else return 0;
}

int main()
{
    int n;
    cin >> n;
    for(int i =0; i < n; i++)
    {
        string temp;
        int korean;
        int english;
        int math;
        cin >> temp;
        cin >> korean >> english >> math;
        vector<int> score;
        score.push_back(korean);
        score.push_back(english);
        score.push_back(math);
        m.insert({temp,score});
    }
    vector<pair<string,vector<int>>> v(m.begin(), m.end());
    sort(v.begin(),v.end(),compare);

    for(int i =0; i < n; i++)
    {
        cout << v[i].first << "\n";
    }
}