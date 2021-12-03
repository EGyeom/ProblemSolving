#include <iostream>
#include <string.h>
#include <stack>
int main()
{
	int T;
	char str[51] = { 0, };
	std::stack<char> st;

	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		while (!st.empty())
		{
			st.pop();
		}
		int check = 0;
		std::cin >> str;
		int len = strlen(str);
		if (len % 2 == 1)
		{
			std::cout << "NO\n";
			check = 1;
		}
		else if (str[0] == ')')
		{
			std::cout << "NO\n";
			check = 1;

		}
		else
		{
			for (int j = 0; j < len; j++)
			{
				if (j != 0)
				{
					if (str[j] == ')')
					{
						if (st.size() == 0)
						{
							std::cout << "NO\n";
							check = 1;
							break;
						}
						else st.pop();
					}
					else st.push(str[j]);
				}
				else st.push(str[j]);
			}
			if (check==0 &&st.size() == 0)
			{
				std::cout << "YES\n";
			}
			else if (check == 0 && st.size() != 0)
			{
				std::cout << "NO\n";
			}
		}
	}


}