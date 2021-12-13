class Solution {
public:
    int maxPower(string s) {
        int countMax = 0;
        int count = 1;
        char temp = s[0];
        for(int i =1; i < s.size(); i++)
        {
            if(s[i] == temp)
            {
                count++;
            }
            else
            {
                temp = s[i];
                countMax = max(countMax,count);
                count = 1;
            }
        }
        return countMax = max(countMax,count);
    }
};
