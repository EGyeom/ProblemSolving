// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;
//         int lowestPrice = prices[0];
//         for(int i = 1; i < prices.size(); i++)
//         {
//             if(prices[i] < lowestPrice)
//             {
//                 lowestPrice = prices[i];
//             }
//             else if(prices[i] > lowestPrice)
//             {
//                 int currentProfit = prices[i] - lowestPrice;
//                 profit = profit > currentProfit ? profit : currentProfit;
//             }
//         }
//         return profit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int minPrice = prices[0];
        for(int i = 1; i < n ; i++)
        {
            if(minPrice < prices[i])
            {
                int currentProfit = prices[i] - minPrice;
                profit = max(profit, currentProfit);
            }

            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};