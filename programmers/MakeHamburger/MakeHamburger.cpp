#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string order = "1231";
    string s_ingredient = "";
    for(int i = 0; i < ingredient.size(); i++)
    {
        s_ingredient += ingredient[i] + '0';
        int sSize = s_ingredient.size();
        if(sSize >= 4)
        {
            if(order == s_ingredient.substr(sSize-4,4))
            {
                answer++;
                s_ingredient.erase(sSize-4,4);
            }
        }
    }
    return answer;
}

int main()
{

}