#include <iostream>

int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;
	num1 = num1 - (num1 - (num1 % 100)) + (num1 - (num1 % 100)) / 100 - (num1 % 10) + (num1 % 10) * 100;
	num2 = num2 - (num2 - (num2 % 100)) + (num2 - (num2 % 100)) / 100 - (num2 % 10) + (num2 % 10) * 100;

	if (num1 > num2)
	{
		std::cout << num1 << std::endl;
	}
	else std::cout << num2 << std::endl;
}