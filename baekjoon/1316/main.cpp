#include <iostream>
#include <string.h>
int main()
{
	int N;
	char str[100][101];
	int len = 0;
	int index = 0;
	int count = 0;
	int check = 0;
	char checker = 0;
	bool change = false;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> str[i];
		len = strlen(str[i]);

		for (int j = 0; j < len; j++)
		{
			checker = str[i][j];
			for (int k = j; k < len; k++)
			{
				if (change == false)
				{
					if (checker == str[i][k]) continue;
					else change = true;
				}
				else
				{
					if (checker == str[i][k])
					{
						check = 1;
						break;
					}
				}
			}
		change = false;
		}
		if (check == 0)
		{
			count++;
			check = 0;
			change = false;
		}
		else
		{
			check = 0;
			change = false;
		}
	}

	std::cout << count << std::endl;
}