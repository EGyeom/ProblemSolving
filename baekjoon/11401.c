#include <stdio.h>
#define MOD 1000000007
#define MAX_N 4000000

long long fact[MAX_N + 1];
long long inv_fact[MAX_N + 1];

// 분할 정복을 이용한 거듭제곱
long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

// 팩토리얼과 역팩토리얼 미리 계산
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    // (N!)^(MOD-2) 계산
    inv_fact[MAX_N] = power(fact[MAX_N], MOD-2);
    
    // (i!)^(-1) = (i+1)!^(-1) * (i+1)
    for (int i = MAX_N-1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

// 이항 계수 계산
long long binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    
    long long numerator = fact[n];
    long long denominator = (inv_fact[k] * inv_fact[n-k]) % MOD;
    
    return (numerator * denominator) % MOD;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    precompute();
    
    printf("%lld\n", binomial(n, k));
    
    return 0;
}
