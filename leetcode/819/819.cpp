/* 
class Solution {
    
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> words;
        int left =0, right = 0;
        int paragraphSize= paragraph.size();
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        for(int i =0; i < paragraphSize; i++)
        {
            if((paragraph[i] >= 65 && paragraph[i] <= 90) ||
               (paragraph[i] >= 97 && paragraph[i] <= 122))
            {
                right = i;
            }
            else
            {
                if(right >= left)
                {
                    string word = paragraph.substr(left, i-left);
                    cout << word << "\n";
                    if(find(banned.begin(), banned.end(), word) == banned.end())
                    {
                        if(words.find(word) == words.end())
                        {
                            words.insert({word,1});
                        }
                        else words[word]++;
                    }
                    left = i+1;
                }
                else left++;
            }
        }
        int max = 0;
        string word;
        for(auto s : words)
        {
            if(s.second > max)
            {
                max = s.second;
                word = s.first;
            }
        }
        
        return word;
    }
}; 
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> words;
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(), ::tolower);
        regex r("[^A-Za-z]");
        paragraph = regex_replace(paragraph,r," ");
        int paragraphSize = paragraph.size();
        string word = "";
        cout << paragraph << "\n";
        for(auto s : paragraph)
        {
            if(isalpha(s)) word.push_back(s);
            else
            {   
                if(word.empty()) continue;
                if(find(banned.begin(), banned.end(), word) == banned.end())
                {
                    if(words.find(word) == words.end())
                    {
                        words.insert({word,1});
                    }
                    else words[word]++;
                }
                word.clear();
            }
        }
        if(!word.empty())
        {
            if(find(banned.begin(), banned.end(), word) == banned.end())
            {
                if(words.find(word) == words.end())
                {
                    words.insert({word,1});
                }
                else words[word]++;
            }
            word.clear();
        }
        int max = 0;
        cout << "size :" << words.size() << "\n";
        for(auto s : words)
        {   
            cout << "word : " << s.first << "count : " << s.second << "\n";
            if(s.second > max)
            {
                max = s.second;
                word = s.first;
            }
        }
        
        return word;
    }
};


int main()
{
   Solution s;

   string paragraph = "a, a, a, a, b,b,b,c, c";
   vector<string> banned = {"a"};

   cout << s.mostCommonWord(paragraph,banned) << "\n"; 

}

/* class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int>m;
        for(int i = 0; i < paragraph.size();){
            string s = "";
            while(i < paragraph.size() && isalpha(paragraph[i])) s.push_back(tolower(paragraph[i++]));
            while(i < paragraph.size() && !isalpha(paragraph[i])) i++;
            m[s]++;
        }
        for(auto x: banned) m[x] = 0;
        string res = "";
        int count = 0;
        for(auto x: m)
            if(x.second > count) res = x.first, count = x.second;
        return res;  
    }
}; */