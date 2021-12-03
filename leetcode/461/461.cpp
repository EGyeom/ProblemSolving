
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = x ^ y;
        int ans = 0;
        while(result!=0)
        {
            if(result % 2 ==1) ans++;
            result = result / 2;
        }
        return ans;
    }
};