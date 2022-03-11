#include <bits/stdc++.h>
using namespace std;
#define CMD_MAX 500000

int main()
{
    cin.tie(NULL);
    list<char> l;
    string input;
    int cmdCount = 0;
    cin >> input;
    for(int i =0; i < input.length(); i++)
    {
        l.push_back(input[i]);
    }
    auto cursor = l.end();
    cin >> cmdCount;
    for(int i =0; i < cmdCount; i++)
    {
        char cmd;
        cin >> cmd;
        switch (cmd)
        {
        case 'L' :
            if(cursor != l.begin()) cursor--;
            break;
        
        case 'D' :
            if(cursor != l.end()) cursor++;
            break;
        
        case 'B' :
            if(cursor != l.begin())
            {
                cursor = l.erase(--cursor);
            }
            break;
        
        case 'P' :
            char c;
            cin >> c;
            l.insert(cursor,c);
            break;
        }
    }
    for(auto c : l)
    {
        printf("%c",c);
    }
    printf("\n");
}