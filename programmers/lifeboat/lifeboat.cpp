#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i = 0;
    int j = people.size() - 1;
    sort(people.begin(), people.end());    
    
    while(i < j && people[j] == limit)
    {
        j--;
        answer++;
    }
    
    while(i <= j)
    {
        if(people[i] + people[j] <= limit)
        {
            i++;
        }
        j--;
        answer++;
    }
    return answer;
}