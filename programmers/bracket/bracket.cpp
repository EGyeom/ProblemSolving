#include <bits/stdc++.h>
using namespace std;

bool isbalanced(string p)
{
    int left = 0;
    for(char& c : p)
    {
        if(c == '(') left++;
    }
    return left == p.size() - left;
}

bool isGood(string p)
{
    if(p.empty()) return true;
    vector<char> st;
    for(char& c : p)
    {
        if(st.empty())
        {
            if(c == ')') return false;
            else st.push_back(c);
        }
        else
        {
            if(c == ')' && st.back() == '(') st.pop_back();
            else  st.push_back(c);
        }
    }
    if(st.empty()) return true;
    else return false;
}

vector<string> separate(string s)
{
    int index = 2;
    vector<string> uv(2);
    string u = s.substr(0,2);
    while(!isbalanced(u))
    {
        u += s.substr(index, 2);
        index+= 2;
    }
    uv[0] = u;
    uv[1] = s.substr(index,s.size() - index);
    return uv;
}
string recursive(string p)
{
    if(p.empty()) return "";
    vector<string> uv = separate(p);
    cout << uv[0] << " " << uv[1] << "\n";
    if(isGood(uv[0]))
    {
        /* 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
            2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
            3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
            3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.  */
        uv[0] += recursive(uv[1]);
        return uv[0];
    }
    else
    {
        /* 
        4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
        4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        4-3. ')'를 다시 붙입니다. 
        4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        4-5. 생성된 문자열을 반환합니다.  */
        string temp = "(";
        temp += recursive(uv[1]);
        temp += ")";
        uv[0].erase(uv[0].begin());
        uv[0].erase(uv[0].end()-1);
        for(char& c : uv[0])
        {
            if(c == '(') c = ')';
            else c = '(';
        }
        temp += uv[0];
        return temp;
    }
    return "";
}

string solution(string p) {
    if(p.empty()) return p;
    string answer = recursive(p);;
    return answer;
}

int main()
{
    cout << solution("()))((()") << "\n";
}

/*
 "(()())()"	"(()())()"
")("	"()"
"()))((()"	"()(())()" 
*/
