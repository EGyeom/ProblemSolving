#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<pair<int,char>> mark_index;
        string reverse;
        for(int i =0; i < s.size(); i++)
        {
            if(isalpha(s[i]))
            {
                reverse.insert(0,1,s[i]);
            }
            else mark_index.push_back({i,s[i]});
        }

        for(int i =0 ; i < mark_index.size(); i++)
        {
            reverse.insert(mark_index[i].first,1,mark_index[i].second);
        }

        return reverse;
    }
};


int main()
{
    Solution s;
    string temp = s.reverseOnlyLetters("Test1ng-Leet=code-Q!");
    cout << temp <<"\n";
    return 0;
}
/* 
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string str = "";
        stack<char>stk;
        for(auto ch: s){
            if(isalpha(ch)){
                
                stk.push(ch);
            }
        }
        
        
        for(char ch: s){
            
             if(isalpha(ch)){
                cout << ch << endl;
                char c = stk.top();
                stk.pop();
                str += c;
            }
            else{
                str+=ch;
            }
        }
        return str;
    }
}; */