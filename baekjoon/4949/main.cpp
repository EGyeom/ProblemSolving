#include <iostream>
#include <vector>
#include <string.h>
int main()
{
	std::vector<int> st;
	while (1)
	{
		char str[101];
		int check = 0;
		st.clear();
		std::cin.getline(str, 101);
		int len = strlen(str);
		if (len == 1 && str[0] == '.')
		{
			check = 1;
			break;
		}
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '.') break;
			if (st.size() == 0)
			{
				if (str[i] == ')' || str[i] == ']')
				{
					std::cout << "no\n";
					check = 1;
					break;
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
					if (st[st.size() - 1] != 1)
					{
						std::cout << "no\n";
						check = 1;
						break;
					}
					else st.pop_back();
				}
				else if (str[i] == ']')
				{
					if (st[st.size()-1] != 2)
					{
						std::cout << "no\n";
						check = 1;
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

		if (st.size() == 0 && check == 0)
		{
			std::cout << "yes" << "\n";
		}
		else if (st.size() != 0 && check == 0)
		{
			std::cout << "no\n";
		}

		

	}


}