#include <bits/stdc++.h>
using namespace std;

int fibCount;
int fib(int n)
{
    if(n == 1 || n == 2)
    {
        fibCount++;
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int f[41];
int fibonacciCount;
int fibonacci(int n)
{
    f[1] = f[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        fibonacciCount++;
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
int main()
{
    int n;
    scanf("%d", &n);
    fib(n);
    fibonacci(n);
    printf("%d %d\n", fibCount, fibonacciCount);
}