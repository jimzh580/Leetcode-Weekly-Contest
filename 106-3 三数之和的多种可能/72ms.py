class Solution:
    def threeSumMulti(self, A, target):
        """
        :type A: List[int]
        :type target: int
        :rtype: int
        """
        c=collections.Counter(A)
        Mod=1000000007
        A=sorted(list(set(A)))
        ans=0
        for i in range(len(A)):
            tar=target-A[i]
            left=i
            right=len(A)-1
            while left<=right:
                if A[left]+A[right]>tar:
                    right-=1
                elif A[left]+A[right]<tar:
                    left+=1
                else:
                    if i==left==right:
                        if c[A[i]]>=3:
                            ans+=c[A[i]]*(c[A[i]]-1)*(c[A[i]]-2)//6
                    elif i==left:
                        if c[A[i]]>=2:
                            ans+=(c[A[i]]*(c[A[i]]-1)//2)*c[A[right]]
                    elif left==right:
                        if c[A[right]]>=2:
                            ans+=(c[A[right]]*(c[A[right]]-1)//2)*c[A[i]]
                    else:
                        ans+=c[A[i]]*c[A[left]]*c[A[right]]
                    ans%=Mod
                    left+=1
                    right-=1
        return ans