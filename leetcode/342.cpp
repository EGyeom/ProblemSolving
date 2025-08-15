class Solution {
public:

    bool isUsingBitManipulation(int n)
    {
        return ((n&(n-1))==0 && (0x55555555 & n) != 0);
    }

    bool isUsingForLoop(int n)
    {
        for(int i = 1; i <= n; i*= 4)
        {
            if(n == i)
                return true;
        }

        return false;
    }

    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;

        return isUsingBitManipulation(n);
    }
};