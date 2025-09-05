class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i = 1; i <= 60; i++)
        {
            long long x = num1 - static_cast<long long>(num2)*i;

            if(x < i)
                return -1;
            
            if(i >= __builtin_popcountll(x))
                return i;
        }

        return -1;
    }
};

/*
after k-operation : num1 - [(2^i1 + num2) + (2^i2 + num2) + ... + (2^ik +num2)]
=> num1 - [(2^i1 + 2^i2 + ... + 2^ik)+ k*num2]
condition for makeing num1 to zero
=> 0 = num1 - [(2^i1 + 2^i2 + ... + 2^ik)+ k*num2]
=> (2^i1 + 2^i2 + ... + 2^ik) = num1 - k*num2
=> (2^i1 + 2^i2 + ... + 2^ik) = x
=> x = num1 - k*num2
*/
