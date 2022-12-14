class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int strs_size = strs.size();
        int str_size = strs[0].size();
        int count = 0;
        for(int i =0; i < str_size; i++)
        {
            for(int j = 0; j < strs_size-1; j++)
            {
                if(strs[j][i] > strs[j+1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};