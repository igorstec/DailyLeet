package DailyLeetCode.java;

class Solution {
    int start=0;
    int end;
    public boolean predictTheWinner(final int[] nums) {
        int len = nums.length;
        if(len<3){
            return true;
        }

        int DP[][] = new int[len][len-1];
        // Ustawiamy najpierw pary a pozniej odwolujac sie do wczesniejszych
        // DP[a][b] = pozycja dlugosci a+1 zaczynajaca sie od b
        for(int i=0; i< len-1; i++){
            DP[1][i]=Math.abs(nums[i]-nums[i+1]);
        }

        int dlg=2;
        //n najwieksza mniejsza parzysta
        while(dlg!=len){
            for(int i=0; i<len-dlg; i++){
                DP[dlg][i]=Math.max(nums[i]-DP[dlg-1][i+1], nums[i+dlg]-DP[dlg-1][i]);
            }
            dlg++;
        }


        return DP[len-1][0]>=0;
        
    }
}