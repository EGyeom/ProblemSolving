#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[100] = {0,};
    scanf("%[^\n]s", str);
    int idx = 0;
    while(str[idx] != '\0')
    {
        if(isalpha(str[idx]))
        {
            if(str[idx] <= 'Z')
            {
                char check = str[idx] - 13 - 'A';
                if(check < 0) str[idx] = 'Z' + check + 1;
                else str[idx] = str[idx] - 13;
            }
            else if(str[idx] >= 'a')
            {
                char check = str[idx] - 13 - 'a';
                if(check < 0) str[idx] = 'z' + check + 1;
                else str[idx] = str[idx] - 13;
            }
        }
        idx++;
        }
        printf("%s\n", str);
}