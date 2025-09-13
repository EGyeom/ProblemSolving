class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        int vowelCnt = 0;
        int consCnt = 0;
        int n = s.size();
        vector<int> letterCnt(26, 0);

        for(int i = 0; i < n; i++)
        {
            if(vowels.find(s[i]) != string::npos)
            {
                letterCnt[s[i] - 'a']++;
                vowelCnt = max(letterCnt[s[i] - 'a'], vowelCnt);
            }
            else
            {
                letterCnt[s[i] - 'a']++;
                consCnt = max(letterCnt[s[i] - 'a'], consCnt);
            }
        }
        
        return vowelCnt + consCnt;
    }
};
