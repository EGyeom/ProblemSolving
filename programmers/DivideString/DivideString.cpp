#include <bits/stdc++.h>
using namespace std;

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int diff = 0;
    int same = 1;
    int sSize = s.size();
    char c = s[0];
    for(int i = 1; i < sSize; i++)
    {
        if(c == s[i])
            same++;
        else diff++;
        if(diff == same)
        {
            answer++;
            diff = 0;
            same = 0;
            if(i == sSize -1)
                break;
            c = s[i+1];
        }
    }
    if(same != diff)
        answer++;
    return answer;
}