class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        bool up;
        if(arr[0] < arr[1]) up = true;
        else return false;
        for(int i = 1; i < arr.size(); i++)
        {
            if(up)
            {
                if(arr[i-1] < arr[i]) continue;
                else if(arr[i-1] == arr[i]) return false;
                up = false;
            }
            else
            {
                if(arr[i-1] > arr[i]) continue;
                return false;
            }
        }
        return !up;
    }
};