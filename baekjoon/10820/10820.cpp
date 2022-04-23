#include <bits/stdc++.h>
using namespace std;

enum INDEX{
    lower = 0,
    upper,
    number,
    space,
};

int main()
{
    // 0 - lower, 1 - upper, 2 - number, 3 - space
    int count[4] = {0,};
    string str;
    while(getline(cin,str))
    {   
        int i = 0;
        int len = str.size();
        if(len == 0) break;
        fill_n(count,4,0);
        while(i < len)
        {   
            if(str[i] == ' ')
            {
                count[space]++;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                count[number]++;
            }
            else if(str[i] >= 'a' && str[i] <= 'z')
            {
                count[lower]++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                count[upper]++;
            }
            i++;
        }
        for(int j =0; j < 4; j++)
        {
            printf("%d ", count[j]);
        }
        printf("\n");
        i = 0;
    }
}