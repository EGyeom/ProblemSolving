#include <iostream>
using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = 1; // 길이 1 초기화
        if (i != 1 && arr[i] == arr[i - 1]) dp[i - 1][i] = 1; // 길이 2 초기화
    }
    
    // 길이가 3 이상인 구간 처리
    for (int len = 3; len <= N; len++) {
        for (int s = 1; s <= N - len + 1; s++) {
            int e = s + len - 1;
            if (arr[s] == arr[e] && dp[s + 1][e - 1] == 1) dp[s][e] = 1;
        }
    }
    
    cin >> M;
    while (M--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
    return 0;
}
