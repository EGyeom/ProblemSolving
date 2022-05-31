/* 민호와 강호 스페셜 저지
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	1330	650	440	49.830%
문제
민호와 강호가 2차원 좌표 평면 위에 있다. 민호는 점 A(Ax, Ay)에서 점 B(Bx, By)를 향해 걸어가고 있고, 강호는 점 C(Cx, Cy)에서 점 D(Dx, Dy)를 향해 걸어가고 있다. 민호와 강호는 동시에 출발하고, 민호가 점 B에 도착하는 순간 강호도 점 D에 도착한다. 또, 두 사람은 항상 일정한 속도로 걸어간다. 두 사람의 거리가 가장 가까울 때, 거리를 구하는 프로그램을 작성하시오.

두 점 (x1, y1), (x2, y2)사이의 거리는 \(\sqrt{(x2-x1)^2 + (y2-y1)^2}\) 이다.

입력
첫째 줄에 Ax, Ay, Bx, By, Cx, Cy, Dx, Dy가 주어진다. 입력으로 주어지는 모든 좌표는 0보다 크거나 같고, 10000보다 작거나 같은 정수이다.

출력
민호와 강호가 가장 가까웠을 때의 거리를 출력한다. 절대/상대 오차는 10-6까지 허용한다.

예제 입력 1 
0 0 1 1 2 2 3 3
예제 출력 1 
2.8284271247
예제 입력 2 
0 0 1 1 1 0 0 1
예제 출력 2 
0.0000000000
예제 입력 3 
0 0 10 20 30 0 5 10
예제 출력 3 
8.2416338387
예제 입력 4 
5 5 10 10 7 2 20 30
예제 출력 4 
2.8745554697 */

//Tenary Search
#include <bits/stdc++.h>
using namespace std;

double minValue = INT_MAX;
double calculrateDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

int main()
{
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);
	double left = calculrateDistance(Ax,Ay,Cx,Cy);
	double right = calculrateDistance(Bx,By,Dx,Dy);
    
	minValue = min(left,right);
	for(int i =0; i < 1000; i++)
	{
		double mid_left_x1 = (2*Ax + Bx)/3;
		double mid_left_y1 = (2*Ay + By)/3;
		double mid_right_x1 = (Ax + Bx*2)/3;
		double mid_right_y1 = (Ay + By*2)/3;
		
		double mid_left_x2 = (2*Cx + Dx)/3;
		double mid_left_y2 = (2*Cy + Dy)/3;
		double mid_right_x2 = (Cx + Dx*2)/3;
		double mid_right_y2 = (Cy + Dy*2)/3;
	
		double mid_left = calculrateDistance(mid_left_x1, mid_left_y1, mid_left_x2, mid_left_y2);
		double mid_right = calculrateDistance(mid_right_x1, mid_right_y1, mid_right_x2, mid_right_y2);
		if(mid_left > mid_right)
		{
			Ax = mid_left_x1;
			Ay = mid_left_y1;
			Cx = mid_left_x2;
			Cy = mid_left_y2;
			minValue = min(minValue, mid_right);
		}
		else
		{
			Bx = mid_right_x1;
			By = mid_right_y1;
			Dx = mid_right_x2;
			Dy = mid_right_y2;
			minValue = min(minValue, mid_left);
		}
	}

    printf("%.10lf\n", minValue);
}