#include <iostream>

int main()
{
	int T;
	int A, B;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> A >> B;
		std::cout << A + B << "\n";
	}
}