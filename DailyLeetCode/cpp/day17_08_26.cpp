#include <iostream>
using namespace std;

class Solution {
    
public:
    int stoneGameV(vector<int>& stoneValue) {
        vector<int> sums;
        vector<vector<int>> DP;
        int len = stoneValue.size();

        sums.resize(len + 1, 0);

        for (int i = 1; i < len+1; ++i) {
            sums[i] = stoneValue[i-1]+sums[i-1];
        }

        DP.assign(len, vector<int>(len, 0));

        int diff=1;
        while(diff<len){
            //We set the difference: right - left
            for(int left=0; left<len-diff;left++){
                int right = left+diff;
                int result=0;
                for(int cut=left+1; cut<=right; cut++){
                    //cut at i-th means its prior to this position
                    int leftsum = sums[cut]-sums[left];
                    int rightsum = sums[right+1] - sums[cut];
                    if(leftsum<rightsum){
                        result = max(result, leftsum + DP[left][cut-1]);
                    }else if(leftsum>rightsum){
                        result = max(result, rightsum + DP[cut][right]);
                    }else{
                        result = max(result, leftsum+max(DP[left][cut-1], DP[cut][right]));
                    }
                }
                DP[left][right] = result;
            }
            diff++;
        }

        return DP[0][len-1];
    }
};