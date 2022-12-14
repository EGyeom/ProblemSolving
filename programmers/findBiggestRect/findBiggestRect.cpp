#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int boardYSize = board.size();
    int boardXSize = board[0].size();
    for(int i = 1 ; i < boardYSize; i++)
    {
        for(int j = 1; j < boardXSize; j++)
        {
            if(board[i][j] == 1)
            {
                board[i][j] = min({board[i-1][j-1], board[i-1][j], board[i][j-1]}) + 1;
                answer = max(board[i][j], answer);
            }
        }
    }

    return answer*answer;
}