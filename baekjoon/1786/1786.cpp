#include <bits/stdc++.h>
using namespace std;


vector<int> makeTable(string pattern)
{
	int patternSize = pattern.length();
	vector<int> table(patternSize, 0);
	int j = 0;
	for(int i = 1; i < patternSize; i++)
	{
		while(j > 0 && pattern[i] != pattern[j])
			j = table[j-1];

		if(pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}

	return table;
}

void KMP(string s, string pattern)
{
	vector<int> table = makeTable(pattern);
	int sSize = s.length();
	int patternSize = pattern.length();
	int j = 0;
	int count = 0;
	vector<int> indexVector;

	for(int i = 0; i < sSize; i++)
	{
		while(j > 0 && s[i] != pattern[j])
			j = table[j-1];
		
		if(s[i] == pattern[j])
		{
			j++;
			if(j == patternSize)
			{
				count++;
				indexVector.emplace_back(i - j + 2);
				j = table[j-1];
			}
		}
	}

	cout << count << "\n";
	for(int& index : indexVector)
	{
		cout << index << " ";
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s, pattern;
	getline(cin, s);
	getline(cin, pattern);

	KMP(s,pattern);
}