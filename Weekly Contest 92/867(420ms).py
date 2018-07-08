class Solution(object):
    def __init__(self):
        self.primes = [2, 3, 5, 7]

    def primePalindrome(self, N):
        """
        :type N: int
        :rtype: int
        """
        d = len(str(N))#长度
        a = 10**((d-1)//2)#用于计算回文，前半段
        b = 10*a #结束条件，不然位数超出
        while True:
            s = str(a)
            #对于一个回文数，先决定它的前半段，则后半段被固定下来了
            n = int(s + s[-1-(d%2)::-1])
            if n >= N and self.is_prime(n):
                return n
            a += 1
            if a == b:#到达了超出位数条件
                if d % 2: a //= 10 #若为奇数位，尝试偶回文
                else: b *= 10 #偶数位则
                d += 1 #位数增加
                

    def is_prime(self, x):#判断是否为素数，打素数表
        if x < 2: return False
        while self.primes[-1]**2 < x:
            self.primes.append(self.next_prime())
        for p in self.primes:
            if p * p > x: break
            if x % p == 0: return False
        return True

    def next_prime(self):#获取下一个素数
        p = self.primes[-1] + 2
        while not self.is_prime(p):
            p += 2
        return p