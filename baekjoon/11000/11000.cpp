#include <bits/stdc++.h>
using namespace std;
bool isvisited[200001];
bool compare(const pair<int,int>&a, const pair<int,int>&b)
{
    if(a.first < b.first)
    {
        return true;
    }
    else if(a.first > b.first)
    {
        return false;
    }
    else
    {
        return (a.second - a.first) < (b.second - b.first);
    }

}

bool compare2(const pair<int,int>&a, const pair<int,int>&b)
{
    return a.first < b.first;
}

int main()
{
    vector<pair<int,int>> v;
    int n;
    cin >> n;
    for(int i =0; i < n ;i++)
    {
        int s,t;
        cin >> s >> t;
        v.emplace_back(make_pair(s,t));
    }

    sort(v.begin(), v.end(), compare);

    int count = 0;

    for(int i =0; i < n; i++)
    {
        if(isvisited[i] == true) continue;
        isvisited[i] = true;
        count++;
        auto iter = lower_bound(v.begin(), v.end(), pair<int,int>(v[i].second,0) , compare2);
        while(1)
        {
            if(iter == v.end())
            {
                break;
            }
            int idx = iter - v.begin();
            if(isvisited[idx] == true)
            {
                ++iter;
            } 
            else
            {
                isvisited[idx] = true;
                iter = lower_bound(v.begin(), v.end(), pair<int,int>((*iter).second,0) , compare2);        
            }
        }
    }
    cout << count << "\n";
}