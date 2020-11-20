#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, A,B;
	std::cin >> T;
	for (int i = 1; i <= T; i++)
	{
		std::cin >> A >> B;
		std::cout << "Case #" << i << ":" << " " << A + B << "\n";
	}
	for (int i = 1; i <= T; i++)
	{
		std::cin >> A >> B;
		std::cout << "Case #" << i << ":" << " " << A << " + "<< B << " = " << A+B <<"\n";
	}


}