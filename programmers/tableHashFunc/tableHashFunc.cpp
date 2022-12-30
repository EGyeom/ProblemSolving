#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int gCol = 0;
bool compare(const vector<int> &a, const vector<int> &b)
{
    if(a[gCol-1] == b[gCol-1])
        return a[0] > b[0];
    
    return a[gCol-1] < b[gCol-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    gCol = col;
    sort(data.begin(), data.end(), compare);

    for(int i = row_begin-1; i < row_end; i++)
    {
        int temp = 0;
        for(const int& n : data[i])
        {
            temp += n % (i+1);
        }
        answer ^= temp;
    }
    return answer;
}