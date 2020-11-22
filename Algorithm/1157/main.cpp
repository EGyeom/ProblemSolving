#include <iostream>
#include <string.h>
int main()
{
	int arr[26] = { 0, };
	int max = 0;
	int index = 0;
	int count = 0;
	char str[1000000] = { 0, };
	std::cin >> str;

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			if (str[i] == char(j) || str[i] == char(j + 32))
			{
				arr[j - 65]++;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == max)
		{
			count++;
		}
	}
	if (count == 1)
	{
		std::cout << char(65 + index) << std::endl;
	}
	else std::cout << "?" << std::endl;
}