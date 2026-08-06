package DailyLeetCode.java;

class Solution {
    private int productOfDigits(int n) {
        if (n == 0) return 0;
        
        int prod = 1;
        while (n > 0 && prod != 0) { 
            prod *= n % 10;
            n /= 10;
        }
        return prod;
    }

    public int smallestNumber(int n, final int t) {
        int prefix = n / 10;
        int lastDigit = n % 10;
        
        int prefixProduct = (prefix != 0) ? productOfDigits(prefix) : 1;
        int currentProduct = prefixProduct * lastDigit;
        
        int stepsToNextTen = 10 - lastDigit;

        while (currentProduct % t != 0 && stepsToNextTen > 0) {
            currentProduct += prefixProduct;
            n++;
            stepsToNextTen--;
        }
        
        return n;
    }
}