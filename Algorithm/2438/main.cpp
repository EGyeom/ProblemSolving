#include <iostream>

int main()
{
	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <num; j++)
		{
			if (j >= num - i -1) std::cout << "*";
			else std::cout << " ";
		}
		std::cout << "\n";
	}
}