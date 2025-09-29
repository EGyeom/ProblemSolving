#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char left[1000000];
    char str[1000000];
    char right[1000000];
    int slen = 0;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        int l = 0, r = 0;
        scanf("%s", str);
        slen = strlen(str);
        for(int j = 0; j < slen; j++)
        {
            char c = str[j];
            switch(c)
            {
                case '<' :
                    if(l > 0)
                    {
                        right[r++] = left[--l];
                    }
                    break;
                case '>':
                    if(r > 0)
                        left[l++] = right[--r];                    
                    break;
                case '-':
                    if(l > 0)
                        l--;
                    break;
                default :
                    left[l++] = c;
                    break;
            }
        }
        
        for(int i = 0 ; i < l; i++)
            printf("%c", left[i]);
        for(int i = r-1; i >=0; i--)
            printf("%c", right[i]);
        printf("\n");
    }
}
