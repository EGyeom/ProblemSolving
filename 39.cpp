class Solution {
public:

    void bt(const vector<int>& candidates, int target, int idx, vector<int>& curCom, vector<vector<int>>& answer)
    {
        if(target == 0)
        {
            answer.push_back(curCom);
            return;
        }

        for(int i = idx; i < candidates.size(); i++)
        {
            int candidate = candidates[i];
            if(target - candidate < 0) break;
            curCom.push_back(candidate);
            bt(candidates, target - candidate, i, curCom, answer);
            curCom.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> combi;
        bt(candidates, target, 0, combi, answer);

        return answer;
    }
};
