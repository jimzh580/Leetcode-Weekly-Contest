class StockSpanner(object):

    a=[]
    n=0
    def __init__(self):
        self.a=[(0,10**6)]
        self.n=0

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        while self.a[-1][1]<=price:
            self.a.pop(-1)
        self.n+=1
        t=self.n-self.a[-1][0]
        self.a.append((self.n,price))
        return t



# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)