class Solution {
public:
    void bt(vector<int>& candidates, int target, int idx, vector<vector<int>>& answer, vector<int>& cur)
    {
        if(target == 0)
        {
            answer.push_back(cur);
            return;
        }

        for(int i = idx; i < candidates.size(); i++)
        {
            if(target < candidates[i]) continue;
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            bt(candidates, target - candidates[i], i+1, answer, cur);
            cur.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> cur;
        bt(candidates, target, 0, answer, cur);
        return answer;
    }
};
