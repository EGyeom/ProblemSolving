
//1번
#include <stdio.h>
#include <string.h>

#define MAX 600000

int main()
{
    char left[MAX] = {0,};
    char right[MAX] = {0,};
    int ltop = 0;
    int rtop = 0;

    char str[MAX] = {0,};
    int m;
    scanf("%s", str);
    scanf("%d", &m);
    
    for(int i = 0; i < strlen(str); i++)
        left[ltop++] = str[i];
    
    for(int i = 0; i < m; i++)
    {
        char cmd;
        scanf(" %c", &cmd);
        if(cmd == 'L')
        {
            if(ltop > 0)
                right[rtop++] = left[--ltop];
        }
        else if(cmd == 'D')
        {
            if(rtop > 0)
                left[ltop++] = right[--rtop];
        }
        else if(cmd == 'B')
        {
            if(ltop > 0)
            {
                ltop--;
            }
        }
        else if(cmd == 'P')
        {
            char c;
            scanf(" %c", &c);
            left[ltop++] = c;
        }
    }
    for(int i = 0; i < ltop; i++)
        printf("%c", left[i]);
    for(int i = rtop - 1; i >= 0; i--)
        printf("%c", right[i]);
    return 0;
}

//2번
#include <stdio.h>
char Rstack[500010];
char Lstack[500010];
int Rcont = 0;
int Lcont = 0;
void Rpush(char x)
{
    Rstack[Rcont++] = x;
}
void Lpush(char x)
{
    Lstack[Lcont++] = x;
}
int Rpop()
{
    return Rstack[--Rcont];
}
int Lpop()
{
    return Lstack[--Lcont];
}
int main(void)
{
    char str[600010];

    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
        Lpush(str[i]);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf(" %c", &c);
        if (c == 'L')
        {
            if (Lcont == 0)
            {
                continue;
            }
            else
            {
                Rpush(Lpop());
            }
        }
        else if (c == 'D')
        {
            if (Rcont == 0)
            {
                continue;
            }
            else
            {
                Lpush(Rpop());
            }
        }
        else if (c == 'B')
        {
            if (Lcont == 0)
            {
                continue;
            }
            else
            {
                Lpop();
            }
        }
        else
        {
            char x;
            scanf(" %c", &x);
            Lpush(x);
        }
    }
    for (int i = 0; i < Lcont; i++)
    {
        printf("%c", Lstack[i]);
    }
    for (int i = Rcont - 1; i >= 0; i--)
    {
        printf("%c", Rstack[i]);
    }
    return 0;
}
