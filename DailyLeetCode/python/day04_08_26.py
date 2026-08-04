from typing import List


class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
            
        min_val = 101
        max_val = 0
        all_ar = [False] * 101
    
        for num in nums:
            if num < min_val:
                min_val = num
            if num > max_val:
                max_val = num
                
            all_ar[num] = True

        return [i for i in range(min_val, max_val + 1) if not all_ar[i]]