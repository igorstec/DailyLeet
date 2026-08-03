package DailyLeetCode.java;

class Solution {
    public String stoneGameIII(final int[] stoneValue) {
        int len = stoneValue.length;
        
        int next1 = 0;
        int next2 = 0;
        int next3 = 0;
        
        int pos = len - 1;

        while (pos >= 0) {
            int opt1 = -next1; 
            int opt2 = pos + 1 < len ? (stoneValue[pos + 1] - next2) : Integer.MIN_VALUE;
            int opt3 = pos + 2 < len ? (stoneValue[pos + 1] + stoneValue[pos + 2] - next3) : Integer.MIN_VALUE;
            
            int current = stoneValue[pos] + Math.max(opt1, Math.max(opt2, opt3));

            next3 = next2;
            next2 = next1;
            next1 = current;

            pos--;
        }
        
        if (next1 > 0) {
            return "Alice";
        } else if (next1 < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
}
