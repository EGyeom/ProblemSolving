#include <iostream>
#include <string.h> // string.h -> strlen

int main()
{
	char str[100] = { 0, };

	int solution[26];

	for (int i = 0; i < 26; i++)
	{
		solution[i] = -1;
	}


	std::cin >> str;
	
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 97; j < 123; j++)
		{
			if (str[i] == char(j))
			{
				if (solution[j - 97] == -1)
				{
					solution[j - 97] = i;
				}
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << solution[i] << " ";
	}


}