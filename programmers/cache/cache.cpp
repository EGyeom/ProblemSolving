#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int citiesSize = cities.size();
    if(cacheSize == 0)
        return citiesSize * 5;
    deque<string> cache;
    
    for(int i =0; i < citiesSize; i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities [i].begin(), ::tolower);
        int current_cacheSize = cache.size();
        int findIdx = -1;
        for(int j = 0; j < current_cacheSize; j++)
        {
            if(cache[j] == cities[i])
            {
                findIdx = j;
                break;
            }
        }
        if(findIdx != -1)
        {
            answer+=1;
            cache.erase(cache.begin() + findIdx);
        }
        else
        {
            if(current_cacheSize == cacheSize)
            {
                cache.pop_front();
            }
            answer+=5;
        }
        cache.emplace_back(cities[i]);
    }
    
    return answer;
}