#include <iostream>

int main()
{
	int A, B;
	std::cin >> A >> B;
	if (A < 0 || B > 10000) return 0;
	printf("%d\n%d\n%d\n%d\n%d", A + B, A - B, A * B, A / B, A % B);
}