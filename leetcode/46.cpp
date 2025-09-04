class Solution {
public:
    vector<bool> isVisited;
    void bt(vector<int>& nums, vector<vector<int>>& answer, vector<int>& cur)
    {
        if(cur.size() == nums.size())
        {
            answer.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(isVisited[i] == true) continue;
            isVisited[i] = true;
            cur.push_back(nums[i]);
            bt(nums, answer, cur);
            isVisited[i] = false;
            cur.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> cur;
        isVisited.resize(nums.size());
        bt(nums, answer, cur);

        return answer;
    }
};
