#include <iostream>
#define _2741
#define _2742
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int N;
	std::cin >> N;
#ifdef _2741
	for (int i = 1; i <= 5; i++)
	{
		std::cout << i << "\n";
	}
#endif

#ifdef _2742
	for (int i = N; i >= 1; i--)
	{
		std::cout << i << "\n";
	}
#endif
}