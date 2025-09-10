class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> us;
        for(auto& friendship : friendships)
        {
            unordered_map<int,int> um;
            bool isFind = false;
            for(auto& lan : languages[friendship[0]-1])
            {
                um[lan] = 1;
            }
            
            for(auto& lan : languages[friendship[1]-1])
            {
                if(um[lan] == 1)
                {
                    isFind = true;
                    break;
                }
            }

            if(isFind == false)
            {
                us.insert(friendship[0]-1);
                us.insert(friendship[1]-1);
            }
        }

        int maxCount = 0;
        vector<int> cnt(n+1, 0);

        for(auto& friendship : us)
        {
            for(auto& lan : languages[friendship])
            {
                cnt[lan]++;
                maxCount = max(maxCount, cnt[lan]);
            }
        }

        return us.size() - maxCount;
    }
};
