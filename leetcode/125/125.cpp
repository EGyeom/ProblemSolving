#include <iostream>
#include <ctype.h>
#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int strSize = s.length();
        string str;
        for(int i =0; i < strSize; i++)
        {
            if(isalnum(s[i]))
            {
                str.push_back(tolower(s[i]));
            }
        }
        int newStrSize = str.length();
        for(int i =0; i < newStrSize/2; i++)
        {
            if(str[i] != str[newStrSize -1 - i])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    Solution s;
    printf("%d\n", s.isPalindrome("A man, a plan, a canal: Panama"));
}