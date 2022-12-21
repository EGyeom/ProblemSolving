#include <string>
#include <vector>

using namespace std;
vector<int> alphabetIndex(26,-1);

vector<int> solution(string s) {
    vector<int> answer;
    int sSize = s.size();
    for(int i =0; i < sSize; i++)
    {
        int c = s[i] - 'a';
        if(alphabetIndex[c] == -1)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - alphabetIndex[c]);
        }
        alphabetIndex[c] = i;
    }
    return answer;
}