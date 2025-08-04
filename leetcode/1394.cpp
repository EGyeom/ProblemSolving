class Solution {
public:
    int findLucky(vector<int>& arr) {

        int n = arr.size();
        vector<int> count(500,0);

        for(int num : arr)
        {
            count[num-1]++;
        }

        for(int i = n-1; i >= 0; i--)
        {
            if(count[i] == i+1)
                return i+1;
        }

        return -1;
    }
};

