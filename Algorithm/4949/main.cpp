#include <iostream>
#include <vector>
#include <string.h>
int main()
{
	std::vector<int> st;
	while (1)
	{
		char str[101];
		std::cin.getline(str, 101);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '.') break;
			if (st.size() == 0)
			{
				if (str[i] == ')' || str[i] == ']')
				{
					std::cout << "yes\n";
				}
				else
				{
					if (str[i] == '(')
					{
						st.push_back(1);
					}
					if (str[i] == '[')
					{
						st.push_back(2);
					}
				}
			}
			else
			{
				if (str[i] == ')')
				{
					if (st[st.back()] != 1)
					{
						std::cout << "no\n";
						break;
					}
					else st.pop_back();
				}
				else if (str[i] == ']')
				{
					if (st[st.back()] != 2)
					{
						std::cout << "no\n";
						break;
					}
					else st.pop_back();
				}
				else if (str[i] == '(')
				{
					st.push_back(1);
				}
				else if (str[i] == '[')
				{
					st.push_back(2);
				}
			}

		}

		if (st.size() == 0)
		{
			std::cout << "yes" << "\n";
		}
		else std::cout << "no\n";

		if (len == 1 && str[0] == '.')
		{
			break;
		}

	}


}