class RecentCounter(object):

    def __init__(self):
        self.pings = []
        self.i = 0

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.pings.append(t)
        while t - self.pings[self.i] > 3000: self.i += 1
        return len(self.pings) - self.i


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)