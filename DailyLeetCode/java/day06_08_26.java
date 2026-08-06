package DailyLeetCode.java;

class Solution {
    private int productOfDigits(int n) {
        int result = n % 10;
        n /= 10;
        while (n != 0 && result != 0) {
            result *= n % 10;
            n /= 10;
        }
        return result;

    }

    public int smallestNumber(int n, final int t) {
        //sprawdz czy nie ma 0 juz
        int multiplier = n / 10;
        int product = n % 10;
        if (multiplier != 0) {
            multiplier = productOfDigits(multiplier);

            product *= multiplier;
            }else{
                multiplier = 1;
            }

            int where0 = 10 - (n % 10);

            while(product % t != 0 && where0>0) {
                product+=multiplier;
                n++;
                where0--;
            }
            return n;
    }
}