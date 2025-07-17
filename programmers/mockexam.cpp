#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v(3,vector<int>());

vector<int> solution(vector<int> answers) {

    vector<int> answer;
    vector<int> score(3,0);
    int answerSize = 0;
    int maxScore = 0;
    v[0] = {1,2,3,4,5};
    v[1] = {2,1,2,3,2,4,2,5};
    v[2] = {3,3,1,1,2,2,4,4,5,5};
    vector<int> remainder = {5,8,10};
    answerSize = answers.size();

    for(int i = 0; i < answerSize; i++)
    {
        for(int j = 0; j < 3; j++)
        {

            if (answers[i] == v[j][i % remainder[j]])
            {
                score[j]++;
                if(maxScore < score[j])
                    maxScore = score[j];
            }
        }
    }

    for(int i =0; i < 3; i++)
    {
        if(maxScore == score[i])
            answer.push_back(i+1);
    }

    return answer;
}