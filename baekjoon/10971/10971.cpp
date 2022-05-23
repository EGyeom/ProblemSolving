#include <bits/stdc++.h>
using namespace std;

int n;
int cnt_;
int min_= INT_MAX;
int sum_;
void func(int start,int now, vector<vector<int>>& v, vector<bool>& checked)
{
    if((cnt_ == n) && (now == start))
    {   
        if(sum_ < min_) min_ = sum_;
        return;
    }
    for(int i =0; i < n; i++)
    {
        if((i == now) || (v[now][i]== 0) || (checked[i] == true)) continue;
        cnt_++;
        checked[i] = true;
        sum_ += v[now][i];
        if(sum_ < min_)
        {
            func(start,i,v,checked);
        }
        sum_ -= v[now][i];
        checked[i] = false;
        cnt_--;;
    }
}

int main()
{
    scanf("%d", &n);
    vector<vector<int>> v(n,vector<int>(n,0));
    vector<bool> checked (n,0);
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
    for(int i =0; i < n; i++)
    {
        func(i,i,v,checked);
    }
    printf("%d\n", min_);
}