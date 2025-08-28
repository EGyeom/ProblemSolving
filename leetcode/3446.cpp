class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxSize = n*2-1;
        vector<vector<int>> v;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                {
                    int temp_i = i;
                    int temp_j = j;
                    vector<int> temp;
                    while(1)
                    {
                        temp.push_back(grid[temp_i][temp_j]);
                        temp_i++;
                        temp_j++;
                        if(temp_i == n || temp_j == n)
                            break;
                    }
                    v.push_back(temp);
                }
                else continue;
            }
        }

        int vSize = v.size();
        for(int i =0; i < vSize; i++)
        {
            if(i != 0 && i <= vSize/2)
                sort(v[i].begin(), v[i].end());
            else sort(v[i].begin(), v[i].end(),greater<int>());
        }

        int i = -1;
        for(int k = 0 ; k < n; k++)
        {
            for(int l = 0; l < n; l++)
            {
                if(k == 0 || l == 0)
                {
                    i++;  
                    int tempk=k;
                    int templ=l;
                    int idx = 0;
                    while(1)
                    {
                        grid[tempk][templ] = v[i][idx++];
                        tempk++;
                        templ++;
                        if(tempk == n || templ == n)
                            break;
                    }
                }
            }
        }

        return grid;
    }
};


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>>mpp;
        int n = grid.size();

        for(int i = 0; i < n ;i++){
            for(int j = 0 ;j < n;j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it : mpp){
            if(it.first < 0){
                sort(begin(it.second),end(it.second));
            }
            else{
                sort(begin(it.second),end(it.second),greater<int>());
            }
        }

        for(int i = n-1;i >=0;i--){
            for(int j = n-1;j >=0 ;j--){
                grid[i][j] = mpp[i-j].back();
                mpp[i-j].pop_back();
            }
        }

        return grid;
    }
};
