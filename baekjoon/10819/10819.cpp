#include <bits/stdc++.h>
using namespace std;
#define ABS(x) (x) < 0 ? (-(x)) : x
int n;
vector<int> check;

int calculrate(vector<int>& temp)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        sum += abs(temp[i-1] - temp[i]);
    }
    return sum;
}


int findMax(vector<int>& v,vector<int>& set, vector<int>& temp,int idx)
{
    int max = -INT_MAX;
    if(idx == n)
    {
        int ans = calculrate(temp);
        return ans;
    }
    for(int i =0; i < n; i++)
    {
        if(set[i] == 1) continue;
        temp.push_back(v[i]);
        set[i] = 1;
        int num = findMax(v,set,temp,++idx);
        max = max > num ? max : num;
        set[i] = 0;
        temp.pop_back();
        idx--;
    }
    return max;
}

int main()
{
    int max = -INT_MAX;
    scanf("%d", &n);
    vector<int> v(n);
    vector<int> set(n,0);
    vector<int> temp;

    for(int i =0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    for(int i =0; i < n; i++)
    {
        temp.push_back(v[i]);
        set[i] = 1;
        int num = findMax(v,set,temp,1);
        max = max > num ? max : num;
        set[i] = 0;
        temp.pop_back();
    }
    printf("%d\n", max);   
}