#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    int h = 3;
    int w = (brown/2) - 1;

    while(w>=h)
    {
        if(w*h == total) break;

        w--;
        h++;
    }
    answer.push_back(w);
    answer.push_back(h);

    return answer;
}