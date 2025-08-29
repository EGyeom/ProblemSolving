class Solution {
public:
    void dfs(int turnedOn, int idx, int hour, int min, vector<string>& result) {
        if (hour > 11 || min > 59) return;
        if (turnedOn == 0) {
            result.push_back(to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min));
            return;
        }
        for (int i = idx; i < 10; ++i) {
            if (i < 6)
                dfs(turnedOn - 1, i + 1, hour, min + (1 << i), result);
            else
                dfs(turnedOn - 1, i + 1, hour + (1 << (i - 6)), min, result);
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        dfs(turnedOn, 0, 0, 0, result);
        return result;
    }
};

/*
class Solution {
public:

    void bt(int limit, int cur, vector<bool>& isVisited, int hour, int min, unordered_set<string>& answer)
    {
        if(hour >= 12 || min >= 60)
            return;
        
        if(limit == cur)
        {
            string sHour = to_string(hour);
            string sMin= to_string(min);
            if(min < 10)
                sMin = "0" + sMin;
            answer.insert(sHour + ":" +sMin);
            return;
        }
        
        for(int i = cur; i < isVisited.size(); i++)
        {
            if(isVisited[i] == false)
            {
                isVisited[i] = true;
                int curNum = 0;
                if(i > 5)
                {
                    curNum = 1 << (i%6);
                    bt(limit, cur+1, isVisited, hour+curNum, min, answer);
                }
                else
                {
                    curNum = 1 << i;
                    bt(limit, cur+1, isVisited, hour, min+curNum, answer);
                }
                isVisited[i] = false;
            }

        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        unordered_set<string> answer;
        vector<bool> isVisited(10,false);
        if(turnedOn > 8)
            return vector<string>();
            
        bt(turnedOn, 0, isVisited, 0,0, answer);
        return vector<string>(answer.begin(), answer.end());
    }
};
*/

