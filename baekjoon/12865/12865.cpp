
#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];
int weights[101];
int values[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    for(int i =1 ; i <= n; i++)
    {
        cin >> weights[i];
        cin >> values[i];
    }

    for(int i =1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(weights[i] <= j)
            {
                dp[i][j] = dp[i-1][j-weights[i]] + values[i];
            }

            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    for(int i =0; i <= n; i++)
    {
        if(i != 0)
        {
            cout << weights[i] << "\t";
        }
        else
        {
            cout << "\t";
        }
        for(int j = 1; j <= k; j++)
        {
            if(i == 0)
            {
                cout << j << "\t";
            }
            else cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << dp[n][k] << "\n";
}
