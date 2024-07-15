# Ptoblem Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        sum_dict = dict()
        count = 0 
        sum_ = 0

        for i in nums:
            sum_+=i

            if sum_==k:
                count+=1
            
            if sum_-k in sum_dict:
                count+=sum_dict[sum_-k]
            
            if sum_ in sum_dict:
                sum_dict[sum_]+=1
            else:
                sum_dict[sum_]=1
        
        return count