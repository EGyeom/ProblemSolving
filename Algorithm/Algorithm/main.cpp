#include <iostream>
//#define bj1000
//#define bj1001
//#define bj1008
//#define bj10998

#ifdef bj1000
int main()
{
	int A, B;
	std::cin >> A >> B;

	std::cout << A + B;
}
#endif

#ifdef bj1001
int main()
{
	int A, B;
	std::cin >> A >> B;
	if (A <= 0 || B >= 10) return 0;
	std::cout << A - B;
}
#endif

#ifdef bj1008
int main()
{
	int A, B;
	std::cin >> A >> B;
	if (A <= 0 || B >= 10) return 0;
	printf("%d", A * B);
}
#endif

#ifdef bj10998
int main()
{
	double A, B;
	std::cin >> A >> B;
	if (A <= 0 || B >= 10) return 0;
	printf("%0.15f", A / B);
}
#endif

