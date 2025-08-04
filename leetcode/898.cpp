/*class Solution {
public:
    void dfs(vector<int>& arr, set<int>& s, int idx, int sum, vector<bool>& ischecked)
    {
        if(!s.contains(sum))
            s.insert(sum);
        if(idx == arr.size())
            return;

        for(int i = idx; i < arr.size(); i++)
        {
            if(ischecked[i] == false)
            {
                ischecked[i] = true;
                sum |= arr[i];
                dfs(arr,s,i+1,sum,ischecked);
                sum |= arr[i];
                ischecked[i] = false;
            }
        }
    }
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> s;
        vector<bool> ischecked(arr.size(), 0);
        for(int num : arr)
            s.insert(num);
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(ischecked[i] == false)
            {
                ischecked[i] = true;
                sum += arr[i];
                dfs(arr,s,i+1,sum,ischecked);
                sum -= arr[i];
                ischecked[i] = false;
            }
        }
        return s.size();
    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
         unordered_set<int> result, current, next;

        for(int num : arr)
        {
          
            next.insert(num);

            for(int j : current)
                next.insert(num | j);

            current = next;
            result.insert(next.begin(), next.end());
            next.clear();
        }

        return result.size();
    }
};

*/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> current, answer;

        for(int i = 0 ; i < arr.size(); i++)
        {
            unordered_set<int> next{arr[i]};

            for(int num : current)
            {
                next.insert(num | arr[i]);
            }

            current = next;
            answer.insert(next.begin(), next.end());
        }
        return answer.size();
    }
};