#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int len = input.size();
    vector<char> v;
    int lineCount = 0;
    int totalCount = 0;
    for(int i =0; i < len; i++)
    {
        if(input[i] == '(')
        {
            v.push_back('(');
            lineCount++;
            totalCount++;
        }
        else
        {
            if(input[i-1] == '(')
            {
                v.pop_back();
                lineCount--;
                totalCount--;
                totalCount += lineCount;
            }
            else
            {
                lineCount--;
            }
        }
    }
    printf("%d\n", totalCount);
}