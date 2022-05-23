#include <bits/stdc++.h>
using namespace std;

int main()
{
    int number =0;
    int a,b;
    int m;
    scanf("%d %d %d", &a, &b, &m);
    for(int i =0; i < m ; i++)
    {
        int temp =0;
        scanf("%d", &temp);
        number*=a;
        number+=temp;
    }
    vector<int> v;
    
    while(number != 0)
    {
        v.push_back(number % b);
        number /= b;
    }
    while(!v.empty())
    {
        printf("%d ", v.back());
        v.pop_back();
    }
    printf("\n");
}