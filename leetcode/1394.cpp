// class Solution {
// public:
//     int findLucky(vector<int>& arr) {

//         int n = arr.size();
//         vector<int> count(500,0);

//         for(int num : arr)
//         {
//             count[num-1]++;
//         }

//         for(int i = n-1; i >= 0; i--)
//         {
//             if(count[i] == i+1)
//                 return i+1;
//         }

//         return -1;
//     }
// };


//reviewed
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> count(500,0);
        int answer = -1;
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            count[arr[i]-1]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(count[arr[i]-1] == arr[i])
                answer = max(answer, arr[i]);
        }

        return answer;
    }
};