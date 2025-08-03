class Solution {
public:
    string makeFancyString(string s) {
        int count = 0;
        int idx = 0;
        int startIdx = 0;
        char cur_char = 0;
        while(idx < s.size())
        {
            if(s[idx] != cur_char)
            {
                if(count >= 3)
                {
                    s.erase(startIdx,count-2);
                    idx -= count - 2;
                }

                count = 1;
                cur_char = s[idx];
                startIdx = idx;
            }
            else
            {
                count++;
            }
            idx++;
        }
        if(count >= 3)
        {
            s.erase(startIdx,count-2);
        }
        return s;
    }
};


/*
 Problem review
class Solution {
public:
    string makeFancyString(string s) {
        string answer = "";
        int cnt = 0;

        for(char c : s)
        {  
            if(answer.empty())
            {
                answer += c;
                continue;
            }

            if(answer.back() != c)
            {
                answer += c;
                cnt = 0;
            }
            else
            {
                cnt++;
                if(cnt >= 2) 
                    continue;
                else answer += c;
            }
        }
        return answer;
    }
};
 */