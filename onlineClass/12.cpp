// 숫자의 총 개수(large input)

#include <cstdio>

int main()
{
    int n = 256;
    int cnt = 0;
    int cmp = 9;
    int temp = 1;
    while(1)
    {
        if(n > cmp)
        {
            cnt += temp * cmp;
            temp++;
            cmp *= 10;
        }
        else
        {
            cnt += (n - ((cmp / 9) -1)) * temp;
            break;
        }
    }

    printf("%d\n", cnt);
}