def valid(a):#数值是否合法
    if a[0] == '0': return len(a) == 1
    return 0 <= int(a) <= 2 ** 31 - 1

def valid2(s, a, b):
    res = [a, b]
    while s:
        n = a + b
        #startswith() 方法用于检查字符串是否是以指定子字符串开头
        if not s.startswith(str(n)) or not valid(str(n)):
            return False
        s = s[len(str(n)):]
        a, b = b, n
        res.append(n)
    return res

class Solution:
    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        for i in range(1, len(S) - 2):
            for j in range(i+1, len(S) - 1):
                a = S[:i]
                b = S[i:j]
                if valid(a) and valid(b) and valid2(S[j:], int(a), int(b)):
                    return valid2(S[j:], int(a), int(b))
        return []
        
S='123456579'
print(Solution.splitIntoFibonacci('self',S))