from heapq import heapify, heappushpop

class Solution:
    def mincostToHireWorkers(self, quality, wage, K):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type K: int
        :rtype: float
        """
        wq = [ (w/q, q) for w,q in zip(wage, quality)]#工资比工作质量
        wq.sort()
        #只需要满足这K个中最大的要求，就满足了K个所有的最低工资要求
        q = [-x[1] for x in wq[:K]]#取前K个的工作质量
        sumq = -sum(q)#工作质量总和
        heapify(q)#数组建堆
        
        minp = sumq * (wq[K-1][0])#第K个
        for i in range(K, len(wq)):#考虑K个之后的
            sumq += wq[i][1]#加入
            sumq += heappushpop(q, -wq[i][1])#将值插入到堆中同时弹出堆中的最小值
            minp = min(minp, sumq * wq[i][0])
        
        return minp
        
quality = [3,1,10,10,1]
wage = [4,8,2,2,7]
K = 3
print(Solution.mincostToHireWorkers('self',quality,wage,K))