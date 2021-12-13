//숫자의 총 개수 (small input)

#include <stdio.h>

int main()
{
    int n;
    int i;
    int cnt = 0;
    int temp;
    scanf("%d", &n);
    for(int i =1; i <= n; i++)
    {
        int temp = i;
        while(temp)
        {
            temp = temp/10;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}