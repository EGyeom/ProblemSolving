#include <iostream>
#include <string.h>
int main()
{

	int time = 0;
	int count = 64;
	char str[16];
	std::cin >> str;
	int len = strlen(str);
	for (int j = 0; j < len; j++)
	{
		for (int i = 65; i <= 90; i++)
		{
			count++;
	
			if (str[j] == i)
			{
				if (i >= 83) count--;
				if (i == 90) count--;
				time += 2 + ((count - 65) / 3) + 1;
				count = 64;
				break;
			}
		}
	}
	std::cout << time << std::endl;

}