class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(30,0);
        for(char c : s)
        {
            int num = c - 'a';
            v[num]++;
        }

        for(int i = 0; i < s.size(); i++)
        {
            int num = s[i] - 'a';
            if(v[num] == 1)
                return i;
        }

        return -1;
    }
};