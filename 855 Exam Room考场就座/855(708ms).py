class ExamRoom:

    def __init__(self, N):
        """
        :type N: int
        """
        self.n = N #座位数
        self.a = [] #就座情况

    def seat(self): #入座
        """
        :rtype: int
        """
        if len(self.a) == 0:#考场无人，就坐0号
            self.a = [0]
            return 0

        cur = self.a[0] #距离
        mark = 0 #最大距离的位置号
        for i in range(len(self.a) - 1):#每两个有人的位置间计算
            h, t = self.a[i], self.a[i + 1]
            m = (h + t) // 2
            if m - h > cur:
                cur = m - h
                mark = m
        
        if (self.n - 1) - self.a[-1] > cur:#计算最后一个位置距离
            cur = (self.n - 1) - self.a[-1]
            mark = self.n - 1

        if mark == 0:#就坐0号
            self.a = [mark] + self.a
        elif mark == self.n - 1:#就坐最后一个位置
            self.a = self.a + [mark]
        else:#插入到其中，保持有序的状态
            idx = None
            for i in range(len(self.a) - 1):
                if self.a[i] < mark < self.a[i + 1]:
                    idx = i + 1
                    break
            self.a = self.a[:idx] + [mark] + self.a[idx:]
        
        return mark

    def leave(self, p):#离座
        """
        :type p: int
        :rtype: void
        """
        idx = None
        for i in range(len(self.a)):
            if self.a[i] == p:
                idx = i
                break

        self.a = self.a[:idx] + self.a[idx + 1:]


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)