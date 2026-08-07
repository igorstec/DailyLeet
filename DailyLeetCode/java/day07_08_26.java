package DailyLeetCode.java;

class Solution {
 
    public String smallestNumber(String num, long t) {
        int[] req = factorize(t);
        if (req == null) return "-1";
 
        int n = num.length();
        int firstZero = num.indexOf('0');
        int startIdx = (firstZero == -1) ? n - 1 : firstZero;
 
        int[] cur = new int[4]; // factor counts of num[0..i-1], maintained while i decreases
        for (int i = 0; i < startIdx; i++) {
            addFactors(cur, num.charAt(i) - '0', 1);
        }
 
        // num itself is a candidate only if it has no '0' at all.
        if (firstZero == -1) {
            addFactors(cur, num.charAt(n - 1) - '0', 1);
            if (covers(cur, req)) return num;
            addFactors(cur, num.charAt(n - 1) - '0', -1);
        }
 
        for (int i = startIdx; i >= 0; i--) {
            int originalDigit = num.charAt(i) - '0';
            for (int d = originalDigit + 1; d <= 9; d++) {
                addFactors(cur, d, 1);
 
                int r2 = Math.max(0, req[0] - cur[0]);
                int r3 = Math.max(0, req[1] - cur[1]);
                int r5 = Math.max(0, req[2] - cur[2]);
                int r7 = Math.max(0, req[3] - cur[3]);
 
                int remainingLen = n - 1 - i;
                int cnt23 = neededCount(r2, r3);      // O(1), no allocation
                int requiredLen = r5 + r7 + cnt23;
 
                if (requiredLen <= remainingLen) {
                    int[] bucket = new int[10];
                    bucket[1] = remainingLen - requiredLen;
                    bucket[5] = r5;
                    bucket[7] = r7;
                    fillDigits(r2, r3, bucket);
 
                    StringBuilder sb = new StringBuilder(n);
                    sb.append(num, 0, i).append((char) ('0' + d));
                    for (int v = 1; v <= 9; v++) {
                        for (int k = 0; k < bucket[v]; k++) sb.append((char) ('0' + v));
                    }
                    return sb.toString();
                }
                addFactors(cur, d, -1);
            }
            if (i > 0) {
                addFactors(cur, num.charAt(i - 1) - '0', -1);
            }
        }
 
        // No same-length answer exists -> answer needs at least n + 1 digits.
        int cnt23 = neededCount(req[0], req[1]);
        int minRequired = req[2] + req[3] + cnt23;
        int newLen = Math.max(n + 1, minRequired);
 
        int[] bucket = new int[10];
        bucket[1] = newLen - minRequired;
        bucket[5] = req[2];
        bucket[7] = req[3];
        fillDigits(req[0], req[1], bucket);
 
        StringBuilder sb = new StringBuilder(newLen);
        for (int v = 1; v <= 9; v++) {
            for (int k = 0; k < bucket[v]; k++) sb.append((char) ('0' + v));
        }
        return sb.toString();
    }
 
    // t -> [a, b, c, d] such that t == 2^a*3^b*5^c*7^d, or null if t has other prime factors.
    private int[] factorize(long t) {
        int[] req = new int[4];
        for (int idx = 0; idx < 4; idx++) {
            int p = new int[]{2, 3, 5, 7}[idx];
            while (t % p == 0) { req[idx]++; t /= p; }
        }
        return t == 1 ? req : null;
    }
 
    private boolean covers(int[] cur, int[] req) {
        return cur[0] >= req[0] && cur[1] >= req[1] && cur[2] >= req[2] && cur[3] >= req[3];
    }
 
    private void addFactors(int[] arr, int d, int sign) {
        switch (d) {
            case 2: arr[0] += sign; break;
            case 3: arr[1] += sign; break;
            case 4: arr[0] += 2 * sign; break;
            case 5: arr[2] += sign; break;
            case 6: arr[0] += sign; arr[1] += sign; break;
            case 7: arr[3] += sign; break;
            case 8: arr[0] += 3 * sign; break;
            case 9: arr[1] += 2 * sign; break;
            default: break; // 1 contributes nothing
        }
    }
 
    // Minimum number of non-1 digits (from {2,3,4,6,8,9}) whose combined factors
    // cover at least r2 twos and r3 threes. Greedy: 9 (two 3's/digit) is the most
    // efficient carrier for 3's, 8 (three 2's/digit) for 2's; a single leftover 2
    // and a single leftover 3 combine into one 6 instead of two separate digits;
    // remaining pairs of 2's become a 4; true leftovers become a bare 3 or 2.
    // This greedy is optimal because 9 and 8 strictly dominate every other digit
    // per unit of the resource they target, and 6 is the only digit that reduces
    // two different leftover counts (of exactly 1 each) with a single digit.
    private int neededCount(int r2, int r3) {
        int cnt = r3 / 2; r3 %= 2;
        cnt += r2 / 3;    r2 %= 3;
        if (r2 >= 1 && r3 >= 1) { cnt++; r2--; r3--; }
        cnt += r2 / 2;    r2 %= 2;
        cnt += r3;                 // 0 or 1 leftover -> one '3'
        cnt += r2;                 // 0 or 1 leftover -> one '2'
        return cnt;
    }
 
    // Same greedy as neededCount, but actually records which digits were used.
    private void fillDigits(int r2, int r3, int[] bucket) {
        bucket[9] += r3 / 2; r3 %= 2;
        bucket[8] += r2 / 3; r2 %= 3;
        if (r2 >= 1 && r3 >= 1) { bucket[6]++; r2--; r3--; }
        bucket[4] += r2 / 2; r2 %= 2;
        if (r3 >= 1) bucket[3]++;
        if (r2 >= 1) bucket[2]++;
    }
}