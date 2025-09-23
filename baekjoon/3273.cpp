#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, x;
    scanf("%d", &n);
    int arr[100000] = {0,};
    bool num[1000001] = {0,};
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        num[arr[i]] = true;
    }

    scanf("%d", &x);

    for(int i = 0; i < n; i++)
    {
        if(x - arr[i] > 1000000)
            continue;

        if(x - arr[i] >= 0 && num[x - arr[i]] == true)
        {
            if(x - arr[i] == arr[i]) continue;
            num[arr[i]] = false;
            answer++;
        }
    }

    printf("%d\n", answer);
    return 0;
}