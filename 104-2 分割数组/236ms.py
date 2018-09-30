class Solution:
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        d=collections.defaultdict(list)
        for i,x in enumerate(A):
            d[x].append(i)
        left=[A[0]]
        maxn=A[0]
        index=1
        while index<len(A):
            #print(A[:index],A[index:])
            if not all(A[i]>=maxn for i in range(index,len(A))):
                index+=1
                if index>=len(A):
                    break
                if A[index-1]>maxn:
                    maxn=A[index-1]
                left.append(A[index-1])
                continue
            #print('1')
            return index
        return False