#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int id_list_size = id_list.size();
    vector<int> answer(id_list_size,0);
    unordered_map<string, vector<string>> m;
    unordered_map<string, int> order;
    vector<vector<int>> v(id_list_size, vector<int>(id_list_size,0));
   for(int i =0; i <id_list_size; i++)
   {
       order.insert({id_list[i],i});
   }

    for(auto iter = report.begin(); iter != report.end(); ++iter)
    {
        int index = 0;
        while((*iter)[index] != ' ')
        {
            index++;
        }
        string reporter = iter->substr(0,index);
        string reportee = iter->substr(index+1);
        if(v[order[reporter]][order[reportee]] == 0)
        {
            m[reportee].push_back(reporter);
           v[order[reporter]][order[reportee]]  = 1;
        }
    }

    for(auto iter = id_list.begin(); iter != id_list.end(); ++iter)
    {
        if(m[*iter].size() >= k)
        {
            for(auto reporter = m[*iter].begin(); reporter != m[*iter].end(); ++reporter)
            {
                answer[order[*reporter]]++;
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    vector<int> print = solution(id_list,report,2);
    for(auto iter = print.begin(); iter != print.end(); ++iter)
    {
        cout << *iter << "\n";
    }
}