#include <psinclude.h>

int lock[8];
int nums[8];

void travesal()

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    for(int i =1; i <= m; i++)
    {
        if(lock[i] == 0)
        {
            nums[i] = i;

        }
    }
}