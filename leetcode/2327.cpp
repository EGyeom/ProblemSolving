class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
    int mod = 1e9+7;
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    long long possible = 0;

    for(int i = 2; i <= n; i++)
    {
        if(i - delay > 0)
        {
            possible = (possible + dp[i-delay] + mod) % mod;
        }

        if(i - forget >0)
        {
            possible = (possible -dp[i-forget] + mod) % mod;
        }

        dp[i] = possible;
    }

    long long answer = 0;
    for(int i = n -forget +1; i <= n; i++)
    {
        answer = (answer + dp[i] + mod) % mod;
    }

    return (int)answer;
    }
};
