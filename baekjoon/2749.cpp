#include <iostream>
#define MOD 1000000
#define CYCLE 1500000 // 주기

using namespace std;

long long fibo[CYCLE] = {0, 1}; // 주기 크기만큼 배열 선언

int main() {
    long long n;
    cin >> n;

    // 피보나치 수열의 나머지를 주기까지 미리 계산
    for (int i = 2; i < CYCLE; i++) {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    }

    // n을 주기로 나눈 나머지에 해당하는 값 출력
    cout << fibo[n % CYCLE] << endl;

    return 0;
}
