class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> answer(n,0);
        if(n == 1)
            return answer;
        int minNum = n/2;
        int idx = 0;
        for(int i = 1; i <= minNum; i++)
        {
            answer[idx++] = -i;
            answer[idx++] = i;
        }

        return answer;
    }
};
