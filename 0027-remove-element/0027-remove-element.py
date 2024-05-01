class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        q = deque()
        size = 0
        
        for i in range(0, len(nums)):
            if nums[i] == val:
                q.append(i)
                size += 1
            elif q:
                nums[q.popleft()] = nums[i]
                nums[i] = val
                q.append(i)
                
        size = max(len(nums) - size, 0)
        return size