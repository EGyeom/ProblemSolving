#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v;
    string input;
    cin >> input;
    int strSize = input.size();
    for(int i =0; i < strSize; i++)
    {
        v.push_back(input.substr(i));
    }

    sort(v.begin(), v.end());

    for(int i =0; i < strSize; i++)
    {
        cout << v[i] << "\n";
    }
}