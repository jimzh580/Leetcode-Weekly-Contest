class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        left=-0xfffff
        maxn=-1
        for i in range(len(seats)):
            if seats[i]==0:
                right=0xfffff
                for j in range(i+1,len(seats)):
                    if seats[j]==1:
                        right=j
                        break
                m=min(i-left,right-i)
                if m>maxn:
                    maxn=m
            else:
                left=i
        return maxn
        
seats=[0,1,0,0,0,0]
print(Solution.maxDistToClosest('self',seats))