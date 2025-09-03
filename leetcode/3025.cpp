class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        const int n = points.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            int y1 = points[i][1], last = -1;
            for(int j = i + 1; j < n; ++j){
                int y2 = points[j][1];
                if(y2 <= y1 && y2 > last){
                    last = y2;
                    ++res;
                }
            }
        }
        return res;
    }
};


class Solution {
public:

    static bool compare(const pair<int,int>& a, const pair<int,int>& b) 
    {
        if(a.first < b.first)
            return true;
        else if(a.first == b.first)
        {
            return a.second > b.second;
        }

        return false; 
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int answer = 0;
        int n = points.size();
        vector<pair<int,int>> v(n);
        for(int i =0; i < n; i++)
        {
            v[i] = {points[i][0], points[i][1]};
        }
        sort(v.begin(), v.end(), compare);

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(v[i].first <= v[j].first && v[i].second >= v[j].second)
                {   bool isPass = true;
                    for(int k = i+1; k < j; k++)
                    {
                        if((v[k].first >= v[i].first && v[j].first >= v[k].first)
                        && (v[k].second >= v[j].second && v[i].second >= v[k].second))
                        isPass = false;
                    }

                    if(isPass)
                        answer++;
                }
            }
        }
        
        return answer;
    }
};
