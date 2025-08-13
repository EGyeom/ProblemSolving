#include <vector>
using namespace std;
static const int MOD = 1'000'000'007;

class Solution {
public:
    vector<vector<int>> dp = vector(301, vector<int>(301,-1));

    int recursive(int target, int x, int num)
    {
        long long power_num = pow(num,x);

        if(power_num == target)
            return 1;
        else if(power_num > target)
            return 0;

        if(dp[target][num] > -1) return dp[target][num];

        int included = recursive(target-power_num, x, num+1);
        int excluded = recursive(target, x, num+1);

        int total = included + excluded;

        dp[target][num] = total % int(1e9+7);

        return dp[target][num];
    }

    int numberOfWays(int n, int x) {
        return recursive(n,x,1);
    }
};


// class Solution {
// public:
//     int numberOfWays(int n, int x) {
//         // collect powers i^x <= n
//         vector<int> powers;
//         for (int i = 1; ; ++i) {
//             long long p = 1;
//             for (int k = 0; k < x; ++k) p *= i;
//             if (p > n) break;
//             powers.push_back((int)p);
//         }

//         vector<long long> dp(n + 1, 0);
//         dp[0] = 1;
//         for (int p : powers) {
//             for (int s = n; s >= p; --s) {
//                 dp[s] = (dp[s] + dp[s - p]) % MOD;
//             }
//         }
//         return (int)dp[n];
//     }
// };


