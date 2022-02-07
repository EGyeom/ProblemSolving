class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()) return t[0];
        int sSize = s.size();
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        for(int i =0; i < sSize; i++)
        {
            if(s[i] == t[i]) continue;
            else return t[i];
        }
        
        return t[sSize];
    }
};