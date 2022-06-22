#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> board, vector<int> Input, int T)
{
    int boardSize = board.size();

    vector<vector<int>> answer(boardSize,vector<int>(boardSize,0));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(int& input : Input)
    {
        int index = 0;
        int direction = (input-1)/boardSize;
        int startIndex = 0;
        cout << input << "\n";
        switch(direction)
        {
            case 0:
                cout << "case 0" << "\n";
                index = input -1;
                startIndex = boardSize-1;
                if(board[boardSize-1][index]==1)
                {
                    for(int i = boardSize-2; i >=0; i--)
                    {
                        if(board[i][index]) board[boardSize-1][index]++;
                        else break;
                    }
                    if(board[boardSize-1][index] >= T) board[boardSize-1][index] = 0;
                    else
                    {
                        board[boardSize-1][index] = 1;
                        startIndex = boardSize-2;
                    }
                }
                for(int i = startIndex; i >=1; i--)
                {
                    if(board[i][index] && board[i-1][index]) continue;
                    board[i][index] = board[i-1][index];
                }
                board[0][index] = 0;
                for (int i = 0; i < board.size(); i++)
                {
                    for (int j = 0; j < board.size(); j++)
                    {
                        cout << board[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
            break;
            case 1:
                cout << "case 1" << "\n";
                index = (input -1) % boardSize ;
                startIndex = 0;
                if(board[index][0]==1)
                {
                    for(int i = 1; i < boardSize; i++)
                    {
                        if(board[index][i]) board[index][0]++;
                        else break;
                    }
                    if(board[index][0] >= T) board[index][0] = 0;
                    else
                    {
                        board[index][0] = 1;
                        startIndex = 1;
                    }
                }
                for(int i = startIndex; i < boardSize-1; i++)
                {
                    if(board[index][i] && board[index][i+1]) continue;
                    board[index][i] = board[index][i+1];
                }
                board[index][boardSize-1] = 0;
                for (int i = 0; i < board.size(); i++)
                {
                    for (int j = 0; j < board.size(); j++)
                    {
                        cout << board[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
            break;
            case 2:
                cout << "case 2" << "\n";
                index = boardSize*(direction+1) - input ;
                startIndex = 0;
                if(board[0][index]==1)
                {
                    for(int i = 1; i < boardSize; i++)
                    {
                        if(board[i][index]) board[0][index]++;
                        else break;
                    }
                    if(board[0][index] >= T) board[0][index] = 0;
                    else
                    {
                        board[0][index] = 1;
                        startIndex =1;
                    }
                }
                for(int i = startIndex; i < boardSize-1; i++)
                {
                    if(board[i][index] && board[i+1][index]) continue;
                    board[i][index] = board[i+1][index];
                }
                board[boardSize-1][index] = 0;
                for (int i = 0; i < board.size(); i++)
                {
                    for (int j = 0; j < board.size(); j++)
                    {
                        cout << board[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
            break;
            case 3:
                cout << "case 3" << "\n";
                index = boardSize*(direction+1) - input;
                startIndex = boardSize-1;
                if(board[index][boardSize-1]==1)
                {
                    for(int i = boardSize-2; i >=0; i--)
                    {
                        if(board[index][i]) board[index][boardSize-1]++;
                        else break;
                    }
                    if(board[index][boardSize-1] >= T) board[index][boardSize-1] = 0;
                    else
                    {
                        board[index][boardSize-1] = 1;
                        startIndex = boardSize-2;
                    }
                }
                for(int i = startIndex; i >=1; i--)
                {
                    // if(board[index][i] && board[index][i-1]) continue;
                    board[index][i] = board[index][i-1];
                }
                board[index][0] = 0;
                for (int i = 0; i < board.size(); i++)
                {
                    for (int j = 0; j < board.size(); j++)
                    {
                        cout << board[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
            break;
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution({ {0,1,0,0,0,0},{0,1,0,1,1,0},{0,1,0,0,0,0},{0,1,0,0,1,0},{0,1,1,0,1,0},{0,0,0,0,0,0} },
        { 14,14,14,14,14,23,17,14 }, 2);

    // solution({ {1,1,0,0,1,0},{0,1,0,1,1,0},{0,1,0,0,0,0},{0,1,0,0,1,0},{0,1,1,0,1,0},{0,0,0,0,0,0} },
    //      { 20,20,20 }, 2);
    return 0;
}