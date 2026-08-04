from typing import List


class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        min_val=101
        max_val=0
        

        for num in nums:
            if(num < min_val):
                min_val = num
            if(num>max_val):
                max_val = num

        size = (max_val - min_val+1)
        all_ar = [False] * size

        for num in nums:
            all_ar[num - min_val]=True
        
        missing = []
        for i in range (size):
            if not all_ar[i]:
                missing.append(i+min_val)

        return missing
            
        
        