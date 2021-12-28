#include <psinclude.h>

int lock[8];
int nums[8];
int count = 0;
void travesal(int start, int n, int m)
{
    if(count == n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= m;i++)
    {
        if(i < start) continue;
        nums[count++] = i;
        travesal(i,n,m);
        count--;
    }
}
int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    for(int i =1; i <= m; i++)
    {
        nums[count++] = i;
        travesal(i,n,m);
        count--;
    }
}