// source : https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/309-best-time-to-buy-and-sell-stock-with-cooldown.html
//
//

//prices = [1, 2, 3, 0, 2]
//maxProfit = 3
//transactions = [buy, sell, cooldown, buy, sell]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MIN, sell = 0, pre_buy = 0, pre_sell = 0;

        for (auto price:prices) {
            pre_buy = buy; // int_min  // -1
            buy = max(pre_sell-price, pre_buy); // -1 // 1
            pre_sell = sell; // 0  // 1
            sell = max(pre_buy+price, pre_sell); // 1 // 1 
        }
        return sell;
    }
};

