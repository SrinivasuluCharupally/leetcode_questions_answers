// source :https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/312-burst-balloons-hard.html`

int maxCoins(vector<int>& iNums) {
    int nums[iNums.size() + 2];
    int n = 1;
    for (int x : iNums) if (x > 0) nums[n++] = x;
    nums[0] = nums[n++] = 1;

    int dp[n][n] = {};

    for (int k = 2; k< n; ++k) { // length, we have to start from 2nd element to find out for index = 0, nums[] is having 0, 1, 2, .... indexes..... for first i = 1, l=0, r=2
        for (int l = 0; l < n-k; ++l) {  // left element
            int r = l+k;  // right element
            for (int i = l+1; i < r; ++i) { // middle element
                dp[l][r] = max(dp[l][r], nums[l]*nums[i]*nums[r]+dp[l][i]+dp[i][r]);
            }
            // cout << "dp[" << l << "][" << r << "]: " << dp[l][r] << endl;
        }
    }

    return dp[0][n-1];
}

