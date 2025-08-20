class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int w = matrix[0].size();
        int h = matrix.size();
        int answer = 0;

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(i == 0 || j == 0)
                {}
                else if(matrix[i][j] == 1)
                    matrix[i][j] = min({matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1]}) + 1;

                answer += matrix[i][j];
            }
        }

        return answer;
    }
};