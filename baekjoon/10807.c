#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[201] = {0,};
    int v = 0;
    for(int i = 0; i < n; i++)
    {
        int a = 0;
        scanf("%d", &a);
        arr[a + 100]++;
    }
    scanf("%d", &v);

    printf("%d\n", arr[v + 100]);
    return 0;
}