class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1
        idx_q = deque()
        
        for i in range(1, len(nums)):
            if len(nums) > i and nums[i] == nums[i-1]: 
                idx_q.append(i)
            elif len(nums) > i:
                k += 1
                if idx_q:
                    nums[idx_q.popleft()] = nums[i]
                    idx_q.append(i)
        if len(nums) == 0:
            return 0
        else:
            return k