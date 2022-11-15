#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
	bool firstWord = true;
	for(char& c : s)
	{
		if(firstWord)
			c = toupper(c);
		else
			c = tolower(c);

		if(c == ' ')
			firstWord = true;
		else
			firstWord = false;
	}
    return s;
}

int main()
{
	string s = "S      T 3people unFollowed me  ";
	solution(s);
}