
//2557
#include <stdio.h>

int main()
{
    printf("Hello World!");
}

#include <stdio.h>
//10171
int main()
{
    printf("\\    /\\");
    printf("\n");
    printf(" )  ( ')");
    printf("\n");
    printf("(  /  )");
    printf("\n");
    printf(" \\(__)|");
    return 0;
}
//10869
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d\n", a+b);
    printf("%d\n", a-b);
    printf("%d\n", a*b);
    printf("%d\n", a/b);
    printf("%d\n", a%b);
    
    return 0;
}

//9498
#include <stdio.h>

int main()
{
    int score;
    scanf("%d", &score);
    
    char c;
    
    if(score >= 90)
        c = 'A';
    else if(score >= 80)
        c = 'B';
    else if(score >= 70)
        c = 'C';
    else if(score >= 60)
        c = 'D';
    else c = 'F';
    
    printf("%c", c);
}

//2752
#include <stdio.h>

int main()
{
    int arr[3];
    
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", arr+i);
    }
       
    for(int i = 0; i < 2; i++)
    {
        for(int j = i+1; j < 3; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for(int i =0 ; i < 3; i++)
        printf("%d ", arr[i]);
        
}
