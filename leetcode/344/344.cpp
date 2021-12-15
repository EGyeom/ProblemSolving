#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int strLength = s.size();
        for(int i =0; i < strLength/2; i++)
        {
            char temp = s[i];
            s[i] = s[strLength - 1 - i];
            s[strLength - 1 - i] = temp;
        }
    }
};