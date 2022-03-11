#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

int main()
{
    char input[101];
    scanf("%s", &input);

    for(int i = 0; i < strlen(input); i++)
    {
        alphabet[input[i] - 'a']++;
    }

    for(int i =0; i < 26; i++)
    {
        printf("%d ", alphabet[i]);
    }

}