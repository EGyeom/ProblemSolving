#include <bits/stdc++.h>
using namespace std;

int visited[50];
int count_;
void dfs(int * arr, int size, int cur)
{
    if(count_ == 6)
    {
        for(int i =0; i < 6; i++)
        {
            printf("%d ",visited[i]);
        }
        printf("\n");
        return;
    }

    for(int i =cur; i < size; i++)
    {
        if(visited[i] != 0) continue;
        visited[count_] = arr[i];
        count_++;
        dfs(arr,size,  i+1);
        count_--;
        visited[count_] = 0;
    }
}

int main()
{
    int arr[50] = {0,}; 
    while(1)
    {
        int n;
        count_ = 0;
        scanf("%d", &n);
        if(n == 0) break;
        for(int i =0 ; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);

        dfs(arr, n, 0);

        for(int i =0; i < n; i++)
        {
            arr[i] = 0;
        }
        printf("\n");
    }
}