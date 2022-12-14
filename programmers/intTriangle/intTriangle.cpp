#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    int triangleSize = triangle.size();
    
    for(int i = 1; i < triangleSize; i++)
    {
        for(int j = 0; j <= i; j++ )
        {
            if(j == 0)
            {
                triangle[i][j] = triangle[i][j] + triangle[i-1][j];
            }
            else if(j == i)
            {
                triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
            }
            else
            {
                triangle[i][j] = triangle[i][j] + max(triangle[i-1][j-1], triangle[i-1][j]);
            }
            
            if(i == triangleSize-1)
                answer = max(answer, triangle[i][j]);
        }
    }
    
    return answer;
}