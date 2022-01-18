/* Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length */

#include <bits/stdc++.h>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int flowerbedSize = flowerbed.size();
      if(n == 0) return true;
      for(int i =0; i < flowerbedSize; i++)
      {
        if(flowerbed[i] == 1) continue;
        else
        {
            if(i == 0)
            {   
                if(flowerbedSize-1 == i) return true;
                if(flowerbed[i+1] == 1) continue;
                else
                {
                    flowerbed[i] =1;
                    n--;
                }
            }        
            else if( i == flowerbedSize-1)
            {
                if(flowerbed[i-1] == 1) continue; 
                else
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else
            {
                if(flowerbed[i-1] != 1 && flowerbed[i+1] != 1)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }   
        }
        if(n == 0)
        {
            return true;
        }
    
      }  
    return false;
    }
};

int main()
{

}