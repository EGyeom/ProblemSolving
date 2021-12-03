class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int index= 0;
        int accountSize = accounts.size();
        vector<vector<string>> ans;
        map<string, int> mailMap;
        for(int i =0; i < accountSize; i++)
        {
            int isFind = -1;
            int mailSize = accounts[i].size();
            vector<string> tempMail;
            tempMail.clear();
            tempMail.push_back(accounts[i][0]);
            for(int j = 1; j < mailSize; j++)
            {
                if(mailMap.find(accounts[i][j]) != mailMap.end())
                {
                    isFind = mailMap[accounts[i][j]];
                    if(isFind == i)
                    {
                        isFind = -1;
                    }
                    continue;
                }
                else
                {
                    mailMap[accounts[i][j]] = i;
                }
                tempMail.push_back(accounts[i][j]);

            }
            if(isFind != -1)
            {
                ans[mailMap[accounts[i][isFind]]].insert(ans[mailMap[accounts[i][isFind]]].end(), tempMail.begin()+1, tempMail.end());
                printf("find");
            }
            else
            {
                ans.push_back(tempMail);
            }
            
        }
        index = ans.size();
        for (int i =0; i < index; i++)
        {
            sort(ans[i].begin(), ans[i].end());
        }
      return ans;
    }
};