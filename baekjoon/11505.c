#include <stdio.h>

#define MOD 1000000007  // 수정: 100000007 -> 1000000007
#define MAX_N 1000000

typedef long long ll;
ll arr[MAX_N];
ll tree[MAX_N*4];

ll init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = arr[start] % MOD;
    }
    
    int mid = (start + end) / 2;
    
    ll left_val = init(node*2, start, mid) % MOD;
    ll right_val = init(node*2+1, mid+1, end)% MOD;
    
    return tree[node] = (left_val * right_val) % MOD;
}

ll update(int node, int start, int end, int idx, int new_val)
{
    if(idx < start || idx > end) return tree[node];
    
    if(start == end) return tree[node] = new_val;
    
    int mid = (start + end) / 2;
    
    ll left_val = update(node*2, start, mid, idx, new_val) % MOD;
    ll right_val = update(node*2+1, mid+1, end, idx, new_val) % MOD;
    
    return tree[node] = (left_val * right_val) % MOD;
}

ll query(int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 1;
    
    if(left <= start && end <= right) return tree[node] % MOD;
    
    int mid = (start + end) / 2;
    
    ll left_val = query(node*2, start, mid, left, right) % MOD;
    ll right_val = query(node*2+1, mid+1, end, left, right) % MOD;
    
    return (left_val * right_val) % MOD;    
}


int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    
    init(1, 0, N - 1);
    
    int total_ops = M + K;
    while (total_ops--) {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        
        if (a == 1) { // update
            int idx = b - 1;
            update(1, 0, N - 1, idx, c);
        } else if (a == 2) { // query
            int left = b - 1;
            int right = c - 1;
            ll result = query(1, 0, N - 1, left, right);
            printf("%lld\n", result);
        }
    }
    
    return 0;
}
