#include <bits/stdc++.h>
using namespace std;
#define abs(X) (X) < 0 ? (-(X)) : (X)
unordered_map<char,bool> brokens;

char func(string& temp, string& subN, int sign)
{
    char c;
    if(temp < subN)
    {
        c = '9';
        while(brokens.find(c) != brokens.end())
        {
            c--;
        }
        temp.push_back(c);
    }
    else if(temp > subN)
    {
        c = '0';
        while(brokens.find(c) != brokens.end())
        {
            c++;
        }
        temp.push_back(c);
    }
    else
    {
        if(brokens.find(subN.back()) != brokens.end())
        {
            while(brokens.find())
        }
        else
        {
            
        }
    }
    
}

int main()
{
    string n;
    int m, min;
    cin >> n >> m;

    for(int i =0; i < m; i++)
    {
        char temp = 0;
        cin >> temp;
        brokens.insert({temp,true});
    }
    min = abs(100-atoi(n.c_str()));
    cout << min << "\n";

    string temp;
    string subN;
    temp.clear();
    subN.clear();
    for(int i =0; i < n.size(); i++)
    {
        subN.push_back(n[i]);
        func(temp,subN,0);
    }
}