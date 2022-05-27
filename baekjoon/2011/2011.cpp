#include <bits/stdc++.h>
using namespace std;

long long dp[5001];
char str[5001];
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    if(str[0] == '0' || str == nullptr)
    {
        printf("0\n");
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 1; i < len; i++)
    {
        if(str[i] != '0')
        {\
            dp[i+1] += dp[i];
        }
        dp[i+1] = dp[i+1] % 1000000;
        if( (str[i-1] == '1') || ((str[i-1] == '2') && (str[i] >= '0' && str[i] <= '6')))
        {
            dp[i+1] += dp[i-1];
        }
        dp[i+1] = dp[i+1] % 1000000;
        if(str[i-1] == '0' && str[i] == '0')
        {
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n", dp[len]);
}
/* 
0
> 0

011 
> 0

0101 
> 0

1203 
> 1

2626 
> 4

2727
> 1

1
> 1

9
> 1

10
> 1

20
> 1

11
> 2

26
> 2

27
> 1

30
> 0

01
> 0

99
> 1

100
> 0

123
> 3

101
> 1

110
> 1

103
> 1

000
> 0

007
> 0

1010
> 1

1012
> 2

2220
> 2

2626
> 4

123456789
> 3

9876543210
> 1



 */

/* if( (str[i-1] > '0' && str[i-1] <= '2' ) && ( str[i] > '0' && str[i] <= '6'))
        {
            dp[i+1] = dp[i];
        }//1~26
        if(str[i] == '0' &&  str[i-1] < '3')
        {
            dp[i+1] = dp[i-1];
        }
        if((str[i-1] > '2' || str[i-1] == '0') && str[i] == '0')
        {
            printf("0\n");
            return 0;
        }
        else
        {
            dp[i+1] = dp[i];
        }
        printf("dp[%d] : %d\t before : %c\t, current : %c\n", i, dp[i], str[i-1], str[i]);
        */


//숫자로 풀었는데 앞이 0일경우를 체크할수가 없음... 
/* int main()
{
    int n;
    int before =-1;
    int current = 0;
    scanf("%d", &n);
    if(n == 0)
    {
        printf("0");
        return 0;
    }
    int idx = 1;
    dp[0] = 1;
    while(n != 0)
    {
        current = n % 10;
        if((before >0 && before <= 6) && (current <= 2))
        {
            dp[idx] = dp[idx-1] + dp[idx-2] ;
        }
        else if((current >= 3 && before == 0))
        {
            printf("0");
            return 0;
        }
        else
        {
            dp[idx] = dp[idx-1]; 
        }
        dp[idx] %= 10000000;
        before = current;
        n /= 10;
        idx++;
    }
    printf("%d\n", dp[idx-1]);
} */