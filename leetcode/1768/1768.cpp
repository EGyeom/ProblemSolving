class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i =0 ;
        while(!word1.empty() && !word2.empty())
        {
            ans.push_back(word1[0]);
            ans.push_back(word2[0]);
            word1.erase(word1.begin());
            word2.erase(word2.begin());
        }
        if(word1.empty() && word2.empty())
        {
            return ans;
        }
        else if(word1.empty())
        {
            return (ans + word2);
        }
        else
        {
            return (ans + word1);
        }
    }
};