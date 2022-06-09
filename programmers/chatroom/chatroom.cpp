#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    unordered_map<int, string> n;
    int strnum =0;
    for(auto& str : record)
    {
        stringstream ss(str);
        string inputStr = "";
        string info[3];
        int index =0;
        while(ss >> info[index++]) {};
        
        if(info[0] == "Enter")
        {
            answer.push_back(info[1] + "님이 들어왔습니다.");
            n.insert({strnum++,info[1]});
        }
        else if(info[0] == "Leave")
        {
            answer.push_back(info[1] + "님이 나갔습니다.");
            n.insert({strnum++,info[1]});
            continue;
        }
        m[info[1]] = info[2];
        
    }

    for(int i =0; i < strnum; i++)
    {
        answer[i].replace(0,n[i].size(),m[n[i]]);
        cout << answer[i] << "\n";
    }
    return answer;
}


int main()
{
    solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
    // string str = "hello world my name is gyeom";
    // stringstream ss(str);
    // string temp;
    // while(ss >> temp)
    // {
    //     cout << temp << "\n";
    // }

}