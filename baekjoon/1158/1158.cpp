/* #include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v(n,0);
    for(int i = 0; i < n; i++)
    {
        v[i] = i+1;
    }
    int count = 0;
    int idx = 0;
    printf("<");
    int add = 0;
    while(1)
    {
        if(add == k-1)
        {
            if(count == n-1)
            {
                printf("%d>\n", v[idx]);
                break;
            }
            else printf("%d, ", v[idx]);
            v[idx] = -1;
            add = 0;
            count++;
        }
        else
        {
            add++;
        }
        idx++;
        if(idx == n) idx = 0;
        while(v[idx] == -1)
        {
            idx++;
            if(idx == n) idx = 0;
        }
    }
} */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    queue<int> q;
    for(int i =0; i < n; i++)
    {
        q.push(i+1);
    }
    printf("<");
    while(1)
    {
        for(int i =1; i < k; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        printf("%d",q.front());
        q.pop();
        if(q.empty())
        {
            printf(">\n");
            break;
        }
        else
        {
            printf(", ");
        }
    }
}