#include <iostream>

int main()
{
	int N1, N2;
	std::cin >> N1 >> N2;
	int temp = N2;
	for (int i = 0; i < 3; i++)
	{
		std::cout << N1 * (temp % 10) << "\n";
		temp /= 10;
	}
	std::cout << N1 * N2 << "\n";
}