#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<char> v;
    int sSize = s.size();
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
                v.push_back(s[i]);
                break;
            }
        }
        if(v.empty()) answer++;
        v.clear();
        s += s[j];
    }
    
    return answer;
}