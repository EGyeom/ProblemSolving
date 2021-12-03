#include <iostream>
#include <string.h>

int main()
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		int num;
		std::cin >> num;
		char str[20] = { 0, };
		std::cin >> str;

		for (int j = 0; j < strlen(str); j++)
		{
			for (int k = 0; k < num; k++)
			{
				std::cout << str[j];
			}
		}
		std::cout << std::endl;

	}


}