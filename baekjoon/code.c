
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

//1475
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int answer = 1;
    int arr[10] = {0};
    while(n > 0)
    {
        int num = n % 10;
        n /= 10;
        if(num == 6 || num == 9)
            arr[6]++;
        else arr[num]++;
    }
    
    arr[6] = (arr[6]-1)/2 + 1;
    int max = 0;
    
    for(int i = 0; i < 10; i++)
    {
        max = max < arr[i] ? arr[i] : max;
    }
    
    printf("%d",max);
}

//13300
#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[2][6] = {0};
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        int s,y;
        scanf("%d %d", &s, &y);
        
        arr[s][y-1]++;
    }
    
    for(int i = 0; i < 2 ; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(arr[i][j] == 0) continue;
            
            answer += (arr[i][j]-1) / k + 1;
        }
    }
    
    printf("%d", answer);
}

//1919
#include <stdio.h>
#include <string.h>

int main()
{
    char a[1001], b[1001];
    int arr[26] = {0,};
       
    scanf("%s %s", a,b);
    int aLen = strlen(a);
    int bLen = strlen(b);
    
    int longer = aLen < bLen ? bLen : aLen;
    
    for(int i = 0; i < longer; i++)
    {
        if(aLen > i)
            arr[a[i]-'a']++; 
        if(bLen > i)
            arr[b[i]-'a']--;
    }
    
    int cnt = 0;
    for(int i = 0 ; i < 26; i++)
    {
        if(arr[i] != 0)
            cnt += arr[i] < 0 ? -arr[i] : arr[i];
    }
    
    printf("%d", cnt);
    
    return 0;
}

//11328
#include <stdio.h>
#include <string.h>

int main()
{
    int n ;
    const char* ip = "Impossible";
    const char* p = "Possible";
    
    scanf("%d", &n);
    int arr[26] = {0,};
    char a[1001],b[1001]; 
    for(int i = 0; i < n; i++)
    {
        memset(a,0,sizeof(char)*1001);
        memset(b,0,sizeof(char)*1001);
        memset(arr, 0,sizeof(int)*26);
        
        scanf("%s %s", a, b);
        
        int aLen = strlen(a);
        int bLen = strlen(b);
        
        if(aLen != bLen)
        {
            printf("%s\n", ip);
            continue;
        }
        
        for(int i = 0 ; i < aLen; i++)
        {
            arr[a[i]-'a']++;
            arr[b[i]-'a']--;
        }
        
        char pass = 1;
        
        for(int i = 0; i < aLen; i++)
        {
            if(arr[a[i]-'a'] > 0)
            {
                pass = 0;
                break;
            }
        }
        
        if(pass == 0)
            printf("%s\n", ip);
        else printf("%s\n", p);
    }
    
    return 0;
    
}

//2577
#include <stdio.h>


int main()
{
    int a,b,c;
    int arr[10] = {0,};
    
    scanf("%d %d %d", &a, &b, &c);
    int ret = a*b*c;
    
    while(ret > 0)
    {
        arr[ret%10]++;
        ret /= 10;
    }
    
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}

//2587

#include <stdio.h>


int main()
{
    int arr[5];
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", arr+i);
        sum += arr[i];
    }
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("%d\n%d", sum/5, arr[2]);
}

//1267
#include <stdio.h>

int main()
{
    int arr[20] = {0,};
    int n;
    scanf("%d", &n);
    
    int m = 0, y = 0;
    for(int i = 0; i < n ; i++)
    {
        scanf("%d", arr+i);
        y += (arr[i]/30+1) * 10;
        m += (arr[i]/60+1) * 15;
    }

    if(m == y)
        printf("Y M %d", m);    
    else if(m < y)
        printf("M %d", m);
    else printf("Y %d", y);
    
    return 0;
}

//10804
#include <stdio.h>

void reverse(int* arr, int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
    return;
}

int main()
{
    int arr[20];
    
    for(int i = 1; i <=20; i++)
        arr[i-1] = i;
    
    for(int i = 0; i < 10; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        reverse(arr,start-1,end-1);
    }
    
    for(int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

//10093
#include <stdio.h>

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if(a > b)
    {
        long long temp = a;
        a = b;
        b = temp;
    }
    int gap = 0;
    if(a == b)
        gap = 0;
    else 
        gap = (int)(b - a - 1);
    printf("%d\n", gap);
    
    if(gap > 0)
    {
        for(long long i = a+1 ; i < b; i++)
        {
            printf("%lld ", i);
        }
    }
    return 0;
}

//2309
#include <stdio.h>
#define N 9

int main()
{
    int arr[N]; 
    int sum = 0;
    char isFind = 0;
    for(int i =0; i <N; i++)
    {
        scanf("%d", arr+i);
        sum += arr[i];
    }
    
    for(int i = 0; i < N-1; i++)
    {
        if(isFind == 1) break;
        for(int j = i+1; j < N; j++)
        {
            if(sum - (arr[i]+arr[j]) == 100)
            {
                isFind = 1;
                arr[i] = -1;
                arr[j] = -1;
                break;
            }
        }
    }
    
    for(int i = 0 ; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }
    
    for(int i = 2; i < N ;i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
