class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        A.sort(key=lambda x:x&1)
        i=0
        while A[i]&1==0:
            i+=1
        l=[]
        j=0
        k=i
        while j<i and k<len(A):
            l.append(A[j])
            l.append(A[k])
            j+=1
            k+=1
        return l