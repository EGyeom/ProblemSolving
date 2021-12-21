// #include <psinclude.h>
// #include <math.h>
// int main()
// {
//     int input;
//     scanf("%d", &input);
//     int multi = 1;
//     float div = 1.0f;
//     bool isFind = false;
//     for(int i = 0; i <= 32; i++)
//     {
//         if(input == multi || input == div)
//         {
//             isFind = true;
//             break;
//         } 
//         else
//         {
//             multi *= 2;
//             div /= 2;
//         }
//     }
//     if(isFind) printf("True\n");
//     else printf("False\n");
// }


class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long multi = 1;
        float div = 1.0f;
        bool isFind = false;
        for(int i = 0; i <= 32; i++)
        {
            if(n == multi || n == div)
            {
                isFind = true;
                break;
            } 
            else
            {
                multi *= 2;
                div /= 2;
                if((n < multi && n >= 1) || (n <= 1 && n > div))
                {
                    break;
                }
            }
        }
        return isFind;    
    }
};