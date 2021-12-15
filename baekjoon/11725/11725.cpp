#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <string.h>

/* 7
1 6
6 3
3 5
4 1
2 4
4 7 */

int main()
{
    int n;
    scanf("%d", &n);
    int * level = new int[n];
    memset(level,0,sizeof(int)*n);
    level[0] = 1;
    std::vector<std::pair<int,int> > v;
    for(int i =0; i < n-1; i++)
    {
        std::pair<int,int> temp;
        scanf("%d %d", &temp.first, &temp.second);
        v.push_back(temp);
    }

    for(int j =1; j <= n; j++)
    {
        for(int i =0; i < n; i++)
        {
            if(v[i].first == j)
            {
                level[v[i].second-1] = j+1; 
            }
            else if(v[i].second == j)
            {
                level[v[i].first-1] = j+1;
            }
        }
        printf("%d ", j);
        for(int i =0; i < n; i++)
        {
            printf("%d ", level[i]);
        }
        printf("\n");
    }
    

}