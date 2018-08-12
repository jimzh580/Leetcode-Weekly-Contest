class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        ans=0
        i=0
        j=len(people)-1
        while i<j:
            if people[i]+people[j]>limit:
                ans+=1
                j-=1
            else:
                ans+=1
                i+=1
                j-=1
        if i==j:ans+=1
        return ans