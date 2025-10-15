#include <stdio.h>

int main()
{
    int n, b, c;
    long long answer = 0; // 오버플로우 방지를 위해 long long
    int a[1000000];
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &b, &c);
    
    for(int i = 0; i < n; i++)
    {
        // 총감독관 1명 무조건 배치
        answer++;
        
        // 부감독관 계산
        int remain = a[i] - b;
        if(remain > 0)
        {
            answer += (remain + c - 1) / c; // 올림 계산
        }
    }
    
    printf("%lld\n", answer);
    return 0;
}
