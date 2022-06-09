#include <bits/stdc++.h>
using namespace std;

/* int solution(string s) {
    int slen = s.length();
    int answer = slen;
    for(int i = 1; i <= slen/2; i++)
    {
        for(int j =0; j < i; j++)
        {
            string ret = s.substr(0,j);
            int count = 1;
            int last = i+j;
            string temp = s.substr(j,i);
            while(last <= slen)
            {
                cout << temp << " " << s.substr(last,i) << "\n";
                if(temp == s.substr(last,i))
                {
                    last += i;
                    count++;
                }
                else
                {
                    if(count != 1) ret += '0' + count;
                    ret += temp;
                    temp = s.substr(last,i);
                    if(temp.length() < i)
                    {
                        ret += temp;
                        break;
                    }
                    last += i;
                    count = 1;
                }
            }
            cout << ret << " : " << ret.length() << "\n";
            if(answer > ret.length()) answer = ret.length();
        }
    }
    return answer;
} */

int solution(string s) {

    int slen = s.length();
    int answer = slen;
    for(int i = 1; i <= slen/2; i++)
    {
            string ret = "";
            int count = 1;
            int last = i;
            string temp = s.substr(0,i);
            while(last <= slen)
            {
                if(temp == s.substr(last,i))
                {
                    last += i;
                    count++;
                }
                else
                {
                    if(count != 1) ret += to_string(count);
                    ret += temp;
                    temp = s.substr(last,i);
                    if(temp.length() < i)
                    {
                        ret += temp;
                        break;
                    }
                    last += i;
                    count = 1;
                }
            }
            if(answer > ret.length()) answer = ret.length();
        
    }
    return answer;
}
int main()
{
    cout << solution("aaaaaaaaaaaaaaaaaab") << "\n";
}