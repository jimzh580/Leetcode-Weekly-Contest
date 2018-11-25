class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        p1=0
        p2=0
        l1=len(pushed)
        l2=len(popped)
        l=[]
        while p1<l1 or p2<l2:
            if l==[]:
                l.append(pushed[p1])
                p1+=1
            elif l[-1]==popped[p2]:
                l.pop()
                p2+=1
            elif l[-1]!=popped[p2]:
                if p1<l1:
                    l.append(pushed[p1])
                    p1+=1
                elif p2<l2:
                    return False
        return True