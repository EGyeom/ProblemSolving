#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int k, int d) {

    long long answer = 0;
    for(long long i = 0; i <= d; i += k)
    {
        long long sqr_d = (long long)d*d;
        long long max_y = sqrt(sqr_d-(i*i))/k; 
        answer += (max_y + 1);
    }
    return answer;
}