public class BestTimeToBuyAndSellStock6 {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;

        if (n <= 0 || k <= 0) {
            return 0;
        }

        if (k * 2 >= n) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                res += Math.max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }

        int[][][] dp = new int[n][k + 1][2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = -1000000000;
                dp[i][j][1] = -1000000000;
            }
        }

        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = Math.max(
                        dp[i - 1][j][0],
                        dp[i - 1][j][1] + prices[i]
                );
                if (j > 0) {
                    dp[i][j][1] = Math.max(
                            dp[i - 1][j][1],
                            dp[i - 1][j - 1][0] - prices[i]
                    );
                }
            }
        }

        int res = 0;
        for (int j = 0; j <= k; j++) {
            res = Math.max(res, dp[n - 1][j][0]);
        }

        return res;
    }
}