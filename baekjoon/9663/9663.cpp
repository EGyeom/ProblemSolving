#include <psinclude.h>

int count = 0;

void blocking(int y, int x, int**map, int n)
{
    for(int i =0; i < n; i++)
    {
        for(int j =0; j <n; j++)
        {
            if(i == y || j == x) map[i][j] =1;
            if(i == j) 
            {
                map[i][j] = 1;
                map[n-1-i][j] = 1;
                map[i][n-1-j] = 1;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int **map = new int*[n];
    for(int i =0; i < n; i++)
    {
        map[i] = new int[n];
    }
    for(int i =0 ; i <n; i++)
    {
        for(int j =0; j <n; j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    blocking(4,4,map,n);
    for(int i =0 ; i <n; i++)
    {
        for(int j =0; j <n; j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}