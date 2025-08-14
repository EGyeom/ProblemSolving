// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         for(int i = 1; i < n; i++)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(nums[i] > nums[j] && dp[i] < dp[j]+1)
//                 {
//                     dp[i] = dp[j]+1;
//                 }
//             }
//         }
//         return *max_element(dp.begin(),dp.end());
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subseq(1,nums[0]);
        int n = nums.size();

        for(int i = 1; i < n; i++)
        {
            int num = nums[i];
            if(num > subseq.back())
                subseq.push_back(num);
            else
            {
                auto it = lower_bound(subseq.begin(), subseq.end(),num);

                *it = num;
            }
        }

        return subseq.size();
    }
};


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);

//     int n;
//     cin >> n;
//     vector<int> nums(n);

//     vector<int> path(n,-1);
//     vector<int> sub;
//     vector<int> idx;

//     for(int i =0; i < n; i++)
//     {
//         cin >> nums[i];

//         if(sub.empty() || nums[i] > sub.back())
//         {
//             if(!sub.empty())
//                 path[i] = idx.back();
//             sub.push_back(nums[i]);
//             idx.push_back(i);
//         }
//         else
//         {
//             auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
//             int pos = it - sub.begin();
//             path[i] = (pos > 0) ? idx[pos-1] : -1;
//             *it = nums[i];
//             idx[pos] = i;
//         }
//     }

//     int cur = idx.back();
//     vector<int> result;
//     while(cur != -1)
//     {
//         result.push_back(nums[cur]);
//         cur = path[cur];
//     }

//     reverse(result.begin(), result.end());
//     cout << result.size() << "\n";

//     for(int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }
// }