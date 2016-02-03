class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        tracker = 0
        counter = 0
        for i in range(len(nums)):
            if tracker >= n:
                return counter
            checker = min(nums[i],n+1) #prevent the case where next nums[i]>>n
            while tracker+1 < checker: #important to have plus 1 here, since we do not worry about consecutives
                counter+=1
                tracker=tracker*2+1
            tracker+=nums[i]
        while tracker<n:
            tracker = tracker*2+1
            counter+=1
        return counter
