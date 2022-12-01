#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<char> v;
    int sSize = s.size();
    bool isBreak = false;
    for(int j = 0 ; j < sSize; j++)
    {
        for(int i = j ; i < sSize + j; i++)
        {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                v.push_back(s[i]);
            }
            else if(v.empty() == false)
            {
                if(v.back() == '{' && s[i] == '}')
                    v.pop_back();
                if(v.back() == '(' && s[i] == ')')
                    v.pop_back();
                if(v.back() == '[' && s[i] == ']')
                    v.pop_back();
            }
            else
            {
                isBreak = true;
                break;
            }
        }
        if(isBreak == false && v.empty()) answer++;
        isBreak = false;
        v.clear();
        s += s[j];
    }
    
    return answer;
}