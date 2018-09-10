class RLEIterator(object):

    def __init__(self, A):
        """
        :type A: List[int]
        """
        self.l=A
        

    def next(self, n):
        """
        :type n: int
        :rtype: int
        """
        while n:
            if self.l==[]:
                return -1
            if self.l[0]>n:
                self.l[0]-=n
                return self.l[1]
            elif self.l[0]==n:
                self.l.pop(0)
                return self.l.pop(0)
            else:
                n-=self.l[0]
                self.l.pop(0)
                self.l.pop(0)
                

# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)