class Solution {
public:

    void bt(string& digits, int idx, vector<vector<char>>& numToChar, vector<string>&answer, string temp)
    {
        if(digits.size() == idx)
        {
            answer.push_back(temp);
            return;
        }
        int num = digits[idx] - '0';
        int chSize = numToChar[num].size();
        for(int i = 0; i < chSize; i++)
        {
            temp += numToChar[num][i];
            bt(digits, idx+1, numToChar, answer, temp);
            temp.pop_back();
        }
        
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits.empty())
            return answer;

        vector<vector<char>> numToChar(10);
        numToChar[2] = {'a','b','c'};
        numToChar[3] = {'d','e','f'};
        numToChar[4] = {'g','h','i'};
        numToChar[5] = {'j','k','l'};
        numToChar[6] = {'m','n','o'};
        numToChar[7] = {'p','q','r','s'};
        numToChar[8] = {'t','u','v'};
        numToChar[9] = {'w','x','y','z'};
        
        bt(digits, 0, numToChar, answer, "");
        return answer;
    }
};
