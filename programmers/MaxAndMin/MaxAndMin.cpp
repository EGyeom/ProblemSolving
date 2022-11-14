#include <bits/stdc++.h>
#include <sstream>
using namespace std;

string solution(string s)
{
	int min = INT_MAX;
	int max = -INT_MAX;
	
	stringstream ss;
	string answer = "";
	ss.str(s);
	int num = 0;
	while(ss >> num)
	{
		if(min > num)
			min = num;
		if(max < num)
			max = num;
	}

	answer.append(to_string(min) + " " + to_string(max));
	return answer;
}