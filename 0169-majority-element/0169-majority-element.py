class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        my_dict = {}
        
        for i in range(0, len(nums)):
            if nums[i] not in my_dict:
                my_dict[nums[i]] = 1
            else:
                my_dict[nums[i]] += 1
            if my_dict[nums[i]] >= len(nums)/2:
                    return nums[i]