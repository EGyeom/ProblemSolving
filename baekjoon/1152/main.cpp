#include <iostream>
#include <string.h>
int main()
{
	char str[1000000] = { 0, };
	int count = 0;

	std::cin.getline(str,1000000);

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != 32)
		{
			if ((i > 0) && str[i - 1] != 32)
			{
				continue;
			}
			else if (str[i] == '\n') continue;
			else
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		if (str[0] == 32 && str[1] == 32)
		{

		}
		else if (str[0] == 0 || str[1] == 0)
		{

		}
		else count++;
	}
	
	printf("%d\n",count);
}