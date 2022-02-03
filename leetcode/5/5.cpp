
class Solution {
public:
    string longestPalindrome(string s) {
        int index = 0;
        int sSize = s.size();
        if(sSize < 2) return s;
        int max_len = 0;
        int startIndex = 0;
        int left, right;
        while(index < sSize)
        {
            left = index;
            right = index;
            while(right < (sSize - 1) && s[right] == s[right+1]) right++;
            index = right + 1;
            while((left > 0 && right < (sSize - 1)) && s[left-1] == s[right+1])
            {
                left--;
                right++;
            }
            int len = right - left +1;
            if(len > max_len)
            {
                startIndex = left;
                max_len = len;
            }
        }
        return s.substr(startIndex,max_len);
    }
};