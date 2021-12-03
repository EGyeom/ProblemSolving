#include <iostream>

int main()
{
	int num;
	int count = 0;
	std::cin >> num;
	for (int i = 1; i <= num; i++)
	{
		int temp = i;
		if ((i / 10) < 10)
		{
			count++;
		}
		else if((i / 10) >= 10 && (i / 10) < 100)
		{
			int minus = 0;
			int a = 0, b = 0, c = 0;
			a = temp % 10;
			temp /= 10;
			b = temp % 10;
			temp /= 10;
			c = temp % 10;

			if (a - b == b - c)
			{
				count++;
			}
		}
	}
	std::cout << count << std::endl;

}