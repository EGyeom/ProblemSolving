/* #include <psinclude.h>

class Solution {
public:
    int bitwiseComplement(int n) {
        int offset = 1;
        while(offset < n) offset = offset*2 + 1;
        return offset - n;
    }
};


int main()
{
    // Solution s;
    // printf("%d\n",s.bitwiseComplement(10));
    char temp = '한';
    printf("%c\n", temp)
    char * ptr = &temp;
    int sum = (char)*(ptr) + (char)*(ptr+1);
    printf("%c %c",(char)*(ptr),(char)*(ptr+1));
    printf("%d %d\n", temp, sum);
} */


#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
struct timeval start, end;

    long mtime, seconds, useconds;    

    gettimeofday(&start, NULL);
    usleep(2000);
    // gettimeofday(&end, NULL);

    // seconds  = end.tv_sec  - start.tv_sec;
    // useconds = end.tv_usec - start.tv_usec;
    printf("%ld %ld\n", start.tv_sec*1000, start.tv_usec/1000.0);
    // mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

    printf("Elapsed time: %ld milliseconds\n", mtime);

    return 0;
}