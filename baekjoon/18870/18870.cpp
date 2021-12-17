/* 예제 입력 1 
5
2 4 -10 4 -9
예제 출력 1 
2 3 0 3 1
예제 입력 2 
6
1000 999 1000 999 1000 999
예제 출력 2 
1 0 1 0 1 0 */

#include <psinclude.h>

/* int main()
{
    int n;
    int index = 0;
    scanf("%d", &n);
    std::vector<int> v;
    std::map<int, int> m;
    for(int i =0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    std::vector<int> ans = v;
    std::sort(v.begin(), v.end());
    for(int i =0; i < n; i++)
    {
        if(m.find(v[i]) == m.end())
        {
            m.insert(std::make_pair(v[i],index++));
        }
    }

    for(int i =0; i < n; i++)
    {
        printf("%d ",m.find(ans[i])->second);
    }
}
 */

int main()
{
    int n;
    int index = 0;
    scanf("%d", &n);
    std::vector<int> v;
    for(int i =0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    std::vector<int> ans = v;
    std::sort(v.begin(), v.end());

    v.resize(std::unique(v.begin(),v.end()) - v.begin());
    
    for(int i =0; i < n; i++)
    {
        printf("%d ",std::lower_bound(v.begin(),v.end(),ans[i])-v.begin());
    }
}
