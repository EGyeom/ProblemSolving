#include <iostream>
#include <string.h>
int main()
{
	char str[101] = { 0, };
	int len = 0;
	int count = 0;
	std::cin >> str;
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		for (int j = 97; j <= 122; j++)
		{
			if (str[i] == j)
			{
				if (str[i] == 'c')
				{
					if (str[i + 1] == '=' || str[i + 1] == '-')
					{
						count++;
						i++;
						break;
					}
					else count++;

				}
				else if (str[i] == 'd')
				{
					if (str[i + 1] == 'z' && str[i+2] == '=')
					{
						count++;
						i += 2;
						break;
					}
					else if (str[i + 1] == '-')
					{
						i++;
						count++;
						break;
					}
					else count++;

				}
				else if (str[i] == 'l')
				{
					if (str[i + 1] == 'j')
					{
						i++;
						count++;
						break;
					}
					else count++;
				}
				else if (str[i] == 'n')
				{
					if (str[i + 1] == 'j')
					{
						i++;
						count++;
						break;
					}
					else count++;
				}
				else if (str[i] == 's')
				{
					if (str[i + 1] == '=')
					{
						i++;
						count++;
						break;
					}
					else count++;
				}
				else if (str[i] == 'z')
				{
					if (str[i + 1] == '=')
					{
						i++;
						count++;
						break;
					}
					else count++;
				}
				else
				{
					count++;
				}

			}
		}
	}

	std::cout << count;
}