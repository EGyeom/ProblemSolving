#include <bits/stdc++.h>

using namespace std;

int main()
{

    unordered_map<long long, unsigned short> m;
    long long max =0;
    int n;
    m.insert({max,0});
    scanf("%d", &n);
    for(int i =0; i < n; i++)
    {
        long long temp;
        scanf("%lld",&temp);
        if(m.find(temp) != m.end())
        {
            m[temp]++;
        }
        else m.insert({temp,1});

        if(m[temp] > m[max])
        {
            max = temp;
        }
        else if(m[temp] == m[max])
        {
            max = temp < max ? temp : max;
        }
    }
    printf("%lld\n", max);
}
