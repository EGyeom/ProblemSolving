class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        int n = 0;
        for(char c : s)
        {
            if(vowels.find(c) != string::npos)
                n++;
        }

        if(n == 0)
            return false;
        else return true;
    }
};
