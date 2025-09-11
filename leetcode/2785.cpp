class Solution {
public:
    string sortVowels(string s) {
        if(s.size() == 1)
            return s;
        vector<int> idxs;
        vector<char> vowels;

        for(int i = 0; i < s.size(); i++)
        {
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            || (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
            {
                idxs.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        for(int i = 0; i < idxs.size(); i++)
        {
            s[idxs[i]] = vowels[i];
        }

        return s;
    }
};
