#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<pair<string,int>> v;
//         vector<vector<string>> ans = {};
//         int strSize = strs.size();
//         if(strSize <= 1)
//         {
//             ans.push_back(strs);
//             return ans;
//         } 
//         vector<string> sorted_str = strs;
//         set<string> s;
//         for(int i =0; i < strSize; i++)
//         {
//             sort(sorted_str[i].begin(), sorted_str[i].end());
//             v.push_back({sorted_str[i],i});
//             s.insert(sorted_str[i]);
//         }
//         vector<string> words;
//         for(auto iter = s.begin(); iter != s.end(); ++iter)
//         {
//             words.push_back(*iter);
//         }

//         vector<string> temp;
//         for(int i =0; i < words.size() ; i++)
//         {
//             temp.clear();
//             for(int j =0 ; j < strSize; j++)
//             {
//                 if(words[i] == v[j].first)
//                 {
//                     temp.push_back(strs[v[j].second]);
//                 }
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(auto s: strs)
        {
            string temp = s;
            sort(s.begin(), s.end());
            m[s].push_back(temp);
        }

        for(auto s : m)
        {
            ans.push_back(s.second);
        }

    }
};
int main()
{

}