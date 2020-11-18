#include <iostream>

int main()
{
	int A, B;
	std::cin >> A >> B;
	if (A < 1 || B > 10000) return 0;
	std::cout << A + B << "\n" << A - B << "\n" << A * B << "\n" << A / B << "\n" << A % B;
}