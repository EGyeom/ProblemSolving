class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = -1;
        int answer = 0;
        for(vector<int> v : dimensions)
        {
            int currentDiagonal = v[0]*v[0] + v[1]*v[1];
            if(maxDiagonal < currentDiagonal)
            {
                maxDiagonal = currentDiagonal;
                answer = v[0] * v[1];
            }
            else if(maxDiagonal == currentDiagonal)
            {
                answer = max(answer, v[0] * v[1]);
            }

        }
        return answer;
    }
};
