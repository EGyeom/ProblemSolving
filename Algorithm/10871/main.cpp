#include <iostream>

int main()
{
	int N, X;
	std::cin >> N >> X;
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		if (temp < X) std::cout << temp << " " ;
	}

}