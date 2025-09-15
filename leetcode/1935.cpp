class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool isPass = false;
        int answer = 0;

        for(int i = 0; i < text.size(); i++)
        {
            if(isPass == true && text[i] != ' ') continue;

            if(text[i] == ' ')
            {
                if(isPass == false)
                    answer++;
                isPass = false;
                continue;
            }

            if(brokenLetters.find(text[i]) != string::npos)
            {
                isPass = true;
            }

            if(isPass == false && i == text.size()-1)
                answer++;
        }

        return answer;
    }
};

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        vector<string> words;
        string word;
        int cnt = 0;
        while(ss >> word)
        {
            words.push_back(word);
        }

        for(string word : words)
        {
            for(char c : word)
            {
                if(brokenLetters.find(c) != string::npos)
                {
                    cnt++;
                    break;
                }
            }
        }

        return words.size() - cnt;
    }
};
