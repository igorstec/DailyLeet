package DailyLeetCode.java;

import java.util.Arrays;

class Solution {

    public int minimumPushes(final String word) {
        int[] letters = new int[26];
        int len = word.length();
        for (int i = 0; i < len; i++) {
            letters[word.charAt(i) - 'a']++;
        }

        Arrays.sort(letters);

        int result = 0;
        int j = 25;

        while (j >= 0 && letters[j] > 0) {
            result += letters[j] * ((25 - j) / 8 + 1);
            j--;
        }

        return result;
    }
}