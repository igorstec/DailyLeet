package DailyLeetCode.java;

class Solution {
    public String stoneGameIII(final int[] stoneValue) {
        int len = stoneValue.length;
        int[] dp = new int[len + 1];
        int pos = len - 1;

        dp[pos] = stoneValue[len - 1];

        if(len>1){
        dp[pos - 1] = stoneValue[len - 2] + Math.max(-dp[pos], stoneValue[pos] - dp[pos + 1]);
        }
        pos -= 2;


        while (pos >= 0) {
            dp[pos] = stoneValue[pos] + Math.max(-dp[pos + 1], Math.max(stoneValue[pos + 1] - dp[pos + 2],
                    stoneValue[pos + 1] + stoneValue[pos + 2] - dp[pos + 3]));
            pos--;
        }
        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
}
