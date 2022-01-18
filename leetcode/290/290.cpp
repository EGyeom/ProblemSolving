/* Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 */
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> m;
        int left=0, right =0;
        int index = 0;
        int patternSize = pattern.size();
        int patternIndex = 0;
        int wordCount =0;
        while(1)
        {                    
            if(s[index] == ' ')
            {
                right = index - left;
                string temp = s.substr(left,right);
                left = index +1;
                wordCount++;
                auto iter = m.find(temp);
                if(iter == m.end())
                {
                    m.insert(pair<string,char>(temp,pattern[patternIndex++]));
                }
                else
                {
                    std::cout << iter->first << " " <<iter->second << ":" << temp <<"\n";
                    if(iter->second != pattern[patternIndex]) return false;
                    patternIndex++;
                }

            }
            if(s[index] == '\0')
            {
                right = index - left;
                string temp = s.substr(left,right);
                wordCount++;
                auto iter = m.find(temp);
                if(iter == m.end())
                {
                    m.insert(pair<string,char>(temp,pattern[patternIndex++]));
                }
                else
                {
                    std::cout << iter->first << " " <<iter->second << ":" << temp <<"\n";
                    if(iter->second != pattern[patternIndex]) return false;
                    patternIndex++;
                }
                break;
            }
            index++;
            if(patternIndex == patternSize) break;
        // std::cout << index << "\n"   ;
        }
        if(patternSize != wordCount) return false;
        string compStr = "";
        for(int i =0; i < patternSize; i++)
        {   
            for(auto iter : m)
            {
                if(iter.second == pattern[i])
                {
                    compStr += iter.first;
                    if(i == patternIndex -1) break;
                    compStr += " ";
                }
            }
        }
        if(compStr == s) return true;
        else return false;
    }
};

int main()
{
    Solution s;
    std::cout << std::boolalpha << s.wordPattern("abba","dog cat cat dog") << "\n";
}