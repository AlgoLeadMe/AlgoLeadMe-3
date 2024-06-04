class Solution(object):
    def searchInsert(self, nums, target):
        for i in range(len(nums)):
            if target <= nums[i]:
                return i
        return i+1