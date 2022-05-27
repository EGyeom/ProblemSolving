#include <bits/stdc++.h>
using namespace std;

int n, s;
int sum_;
int count_;
int arr[21];
int checked[21];
void dfs(int now)
{
    for(int i =now; i <= n; i++)
    {
        if(checked[i] == true) continue;
        checked[i] = true;
        sum_ += arr[i];
        if(sum_ == s)
        {
            count_++;
        }
        dfs(i +1);
        sum_ -= arr[i];
        checked[i] = false;
    }
}

int main()
{
    scanf("%d %d", &n, &s);
    for(int i =1; i <=n; i++)
    {
        scanf("%d", &arr[i]);
    }
    dfs(1);
    printf("%d\n", count_);
}