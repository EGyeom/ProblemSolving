#include <bits/stdc++.h>
using namespace std;
//BFS 로 풀어야함
/* int min_ = INT_MAX;
int arr[1000001];

void func(int initNum, int num, int target, int count, int cal)
{
    printf("%d %d %d %d %d %d\n", initNum, num,target,count,arr[num], min_);
    // if(arr[target] != 0 && count >=arr[target]) return;
    if(arr[num] == 0) arr[num] = count;
    else if(count < arr[num]) arr[num] = count;
    else return ;

    if(num == target)
    {
        min_ = count < min_ ? count : min_;
        return;
    }
    else if(num <= 0 || num == initNum) return;
    else if(num > target)
    {
        int temp = count + num - target;
        if(min_ > temp) min_ = temp;
    }
    else
    {
        if(cal & 1) func(initNum,num+1,target,count+1,1);
        if(cal & 2) func(initNum,num-1,target,count+1,2);
        func(initNum,num*2,target,count+1,3);
    }
}

int main()
{
    int n, k;
    int count_ = 1;
    scanf("%d %d", &n, &k);
    printf("initNum, num,target,count,arr[num], min_\n");
    if(n != k)
    {
        func(n,n*2,k,count_,3);
        func(n,n+1,k,count_,1);
        func(n,n-1,k,count_,2);
    }
    else
    {
        min_ = 0;
    }
    printf("%d\n", min_);
} */


#include <bits/stdc++.h>
using namespace std;

int isvisited[100001];

int bfs(int& n, int& k)
{
    int ret = 0;
    if(n > k)
    {
        ret = n - k;
        return ret;
    }
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {   
        int now = q.front();
        q.pop();
        if(now == k)
        {
            ret = isvisited[now];
            break;
        }
        int ways[] = {now-1, now+1, now*2};
        for(int i =0; i < 3; i++)
        {
             if(ways[i] <= 100000 && ways[i] >= 0 && isvisited[ways[i]] == 0 )
            {
                if(ways[i] > k) isvisited[ways[i]] = isvisited[now] + ways[i] - k;
                else isvisited[ways[i]] = isvisited[now] +1;
                q.push(ways[i]);
            }
        }
    }
    return ret;
}

 int main()
 {
     int n, k ;
     scanf("%d %d", &n, &k);
     printf("%d\n",bfs(n,k));
 }
