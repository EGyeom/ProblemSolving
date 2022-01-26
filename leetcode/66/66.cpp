#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int digitSize = digits.size();
    bool carry = false;
    digits[digitSize-1]++;
    if(digits[digitSize-1]==10)
    {
        carry = true;
        digits[digitSize-1] = 0;
    }

    for(int i = digitSize-2; i >= 0; i--)
    {
        if(carry)
        {
            digits[i]++;
            if(digits[i] == 10)
            {
                digits[i] = 0;
            }
            else carry = false;
        }
        else
        {
            break;
        }   
    }

    if(carry)
    {
        digits.insert(digits.begin(),1);
    }
    return digits;
    }
};

int main()
{
    Solution s;
    vector<int> input = {9};
    vector<int> ans = s.plusOne(input);
    for(auto s : ans)
    {
        cout << s <<"\n";
    }
}


    //     int digitSize = digits.size();
    //     long long num = digits[digitSize-1];
    //     for(int i = digitSize-2; i >=0; i++)
    //     {
    //         num *= 10;
    //         num += digits[i];
    //     }

    //     vector<int> ans;
    //     num += 1;
    //     while(num != 0)
    //     {
    //         int temp = num % 10;
    //         ans.insert(ans.begin(),temp);
    //         num /= 10;
    //     }
    // return ans;


 /*    vector<int> plusOne(vector<int>& digits) {
    for (int i=digits.size(); i--; digits[i] = 0)
        if (digits[i]++ < 9)
            return digits;
    digits[0]++;
    digits.push_back(0);
    return digits;
} */