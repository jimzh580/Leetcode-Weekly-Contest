import heapq
class FreqStack:

    def __init__(self):
        self.dic,self.he,self.k={},[],0

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if x not in self.dic: self.dic[x]=1
        else: self.dic[x]+=1
        heapq.heappush(self.he,(-self.dic[x],self.k,-x))
        self.k-=1
        
        

    def pop(self):
        """
        :rtype: int
        """
        _,_,n=heapq.heappop(self.he)
        n=-n
        self.dic[n]-=1
        if not self.dic[n]: del self.dic[n]
        return n
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()