class Solution {
public:

    bool isContainZero(int num)
    {
        while(num != 0)
        {
            if(num % 10 == 0) return true;
            
            num /= 10;
        }

        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        int i = 1;
        for(i; i < n; i++)
        {
            if(!isContainZero(i) && !isContainZero(n-i))
                break;
        }

        return {i, n-i};
    }
};
