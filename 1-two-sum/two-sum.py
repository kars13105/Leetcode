class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        A=[]
        for i in range(len(nums)):
            A.append((nums[i],i))

        A.sort()

        i = 0
        j=len(nums)-1

        while i<j :
            sum = A[i][0] + A[j][0]

            if sum == target:
                return [A[i][1],A[j][1]]

            elif sum<target:
                i+=1

            else: j-=1

        return []
