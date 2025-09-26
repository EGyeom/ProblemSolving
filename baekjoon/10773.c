#include <stdio.h>

int main()
{
    long long answer = 0;
    int n;
    scanf("%d", &n);
    
    int arr[100000];
    int idx = 0;
    int i = 0;
    while(i < n)
    {
        int num;
        scanf("%d", &num);
        
        if(num == 0)
        {
            idx--;
        }
        else
        {
            arr[idx++] = num;
        }
       i++;
    }
 
    for(i = 0; i < idx; i++)
    {
        answer += arr[i];
    }
    
    printf("%lld", answer);
    
    return 0;
    
}
