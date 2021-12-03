#include <iostream>

int main()
{
	int H, M;
	std::cin >> H >> M;
	try
	{
		if ((H < 0 || H > 23) || (M < 0 || M >59))
			throw H;
		if (M - 45 < 0)
		{
			if (H - 1 < 0)
			{
				std::cout << 24 + (H - 1) << " " << 60 + (M - 45);
			}
			else std::cout << H - 1 << " " << 60 + (M - 45);
		}
		else std::cout << H << " " << M - 45;
	}
	catch (...)
	{
		return 0;
	}

}