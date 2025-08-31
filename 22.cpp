class Solution {
public:
    vector<string> answer;

    void backTracking(int n, int l, int r, string current)
    {
        if(n*2 == current.size())
            answer.push_back(current);
        
        if(l < n)
            backTracking(n, l+1, r, current + "(");
        if(r < l)
            backTracking(n, l, r+1, current + ")");

        return;
    }
    
    vector<string> generateParenthesis(int n) {
        
        backTracking(n, 0, 0, "");
        return answer;
    }
};


class Solution {
public:

    void dfs(int n, int l, int r, string temp, vector<string>& answer)
    {
        if(n < l || n < r)
            return;

        if(n*2 == l+r)
        {
            int pass = 0;
            for(int i = 0; i < n*2; i++)
            {
                if(pass < 0) return;
                if(temp[i] == '(') pass++;
                else pass--;
            }
            answer.push_back(temp);
        }
        for(int j = 0; j < 2; j++)
        {
            if(j == 0)
            {
                temp += "(";
                l++;
            }
            else
            {
                temp += ")";
                r++;
            }
            dfs(n, l, r, temp, answer);
            temp.pop_back();
            j == 0 ? l-- : r--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        dfs(n,0,0,"",answer);

        return answer;   
    }
};
