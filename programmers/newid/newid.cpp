#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = new_id;
    // step 1
    transform(answer.begin(),answer.end(), answer.begin(), ::tolower);
    //step 2
    int index =0;
    while(index < answer.length())
    {
        if(isalnum(answer[index]) || (!isalnum(answer[index]) &&
        ((answer[index] == '-') || (answer[index] == '_') || (answer[index] == '.'))))
        {
            //step 3
            index++;
        }
        else answer.erase(answer.begin() + index);
    }
    index = 0;
    while(index +1 < answer.length())
    {
        if(answer[index] == '.' && answer[index+1] == '.')
        {
            answer.erase(answer.begin() + index + 1);
        }
        else index++;
    }
    if(answer.front() == '.') answer.erase(answer.begin());
    if(answer.back() == '.') answer.erase(answer.end() -1);

    if(answer.empty()) answer.push_back('a');
    if(answer.size() >= 16) answer = answer.substr(0,15);
    while(answer.size() <3)
    {
        answer.push_back(answer.back());
    }
    return answer;
}

int main()
{
    // solution("...!@BaT#*..y.abcdefghijklm.");
    // solution("z-+.^.");
    // solution("=.=");
    // solution("123_.def");
    // solution("abcdefghijklmn.p");
    // solution("-_.-~!@#$%^&*()=+[{]}:?,<>/");
    solution("-.~!@#$%&*()=+[{]}:?,<>/.-");
    solution("./././././abcd/././././.");
}