#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    int str_len = s.size();
    for(int i = 0; i < str_len; )
    {
        answer *= 10;
        if(s[i] >= '0' && s[i] <= '9')
        {
            answer += s[i] - '0';
            i++;
        }
        else
        {
            switch (s[i])
            {
            case 'z' :
                answer += 0;
                i += 4;
                break;
            case 'o' :
                answer += 1;
                i += 3;
                break;
            case 't' :
                if(s[i+1] == 'w')
                {
                    answer+= 2;
                    i+= 3;
                }
                else
                {
                    answer+= 3;
                    i+= 5;
                }
                break;
            case 'f' :
                if(s[i+1] == 'o')
                {
                    answer+= 4;
                    i+= 4;
                }
                else
                {
                    answer+= 5;
                    i+= 4;
                }
                break;
            case 's' :
                if(s[i+1] == 'i')
                {
                    answer+= 6;
                    i+= 3;
                }
                else
                {
                    answer+= 7;
                    i+= 5;
                }
                break;
            case 'e' :
                answer += 8;
                i+= 5;
                break;
            case 'n' :
                answer += 9;
                i+= 4;
                break;
            }
        }
    }
    return answer;
}

int main()
{
     << solution("123") << "\n";
}