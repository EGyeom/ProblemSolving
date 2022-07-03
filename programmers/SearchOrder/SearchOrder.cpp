#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {

	vector<int> answer;
	unordered_map<string,vector<int>> um;

	for(string& s : info)
	{
		stringstream ss(s);
		string word[5];
		ss >> word[0] >> word[1] >> word[2] >> word[3] >> word[4];
		int score = stoi(word[4]);
		string str;
		for(int i =0; i < 16; i++)
		{	
			str.clear();
			for(int j = 0; j < 4; j++)
			{
				str += (i & (1<<j)) ? word[j] : "-";
			}
			um[str].push_back(score);
		}
	}
	for(auto& s : um)
	{
		sort(s.second.begin(), s.second.end());
	}

	for(string& q : query)
	{
		stringstream ss(q);
		string word[5];
		for(int i =0; i < 4; i++)
			ss >> word[i] >> word[4];
		vector<int>& scores = um[word[0] + word[1] + word[2] + word[3]];
		answer.push_back(scores.size() - (lower_bound(scores.begin(), scores.end(), stoi(word[4])) - scores.begin()));
	}

	return answer;
}

int main()
{

	
}