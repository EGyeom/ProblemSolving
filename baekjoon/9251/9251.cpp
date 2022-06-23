/*
LCS
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
0.1 초 (하단 참고)	256 MB	52535	21178	15562	40.289%
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제 입력 1
ACAYKP
CAPCAK
예제 출력 1
4 */


#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string s1,s2;

//최초 풀이 시간초과

/*
int ret;
int LCS(int i, int j)
{
    if(i < 0 || j < 0)
    {
        return 0;
    }
    if(dp[i][j]) return dp[i][j];
    if(s1[i] == s2[j])
    {
        return dp[i][j] = LCS(i-1, j-1) + 1;
    }
    else
    {
        return dp[i][j] = max(LCS(i-1,j),LCS(i,j-1));
    }
} */

int LCS()
{
    int i,j;
    for(i = 1; i <= s1.size(); i++)
    {
        for(j =1; j <= s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[i-1][j-1];
}


int main()
{
    cin >> s1 >> s2;
    // cout << LCS(s1.size(), s2.size()) << "\n";
    cout << LCS() << "\n";
}
