class Solution:
    def twoSum(self, nums, target):
        numandindex={}
        for i in range(len(nums)):
            other=target-nums[i]
            if other in numandindex:
                return[numandindex[other],i]
            numandindex[nums[i]]=i
solution=Solution()
ans=solution.twoSum([2,7,11,15],9)
print(ans)
