class Solution:
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        
        data = [(p, s, (target - p) / s) for (p, s) in zip(position, speed)]
        #三元组存储(位置、速度、时间)
        data.sort(key=lambda x: x[0])#按位置排序

        t = [e[2] for e in data]#取每辆车要用的时间
        n = len(t)#车辆数

        mark = [None for _ in range(n)]
        for i in range(n)[::-1]:#从后往前，因为后面的更靠近终点
            cur = i + 1#与后面的匹配
            while cur < n:
                if t[cur] < t[i]:#用时更长而位置又前，肯定不是一个车队
                    if mark[cur] == None:#无标记
                        cur = n
                    else:
                        cur = mark[cur]
                else:#用时更短则可归入一个车队
                    break

            if cur == n:#没找到车队
                pass
            else:#归入车队
                mark[i] = cur
        
        for i in range(n):#剩余的自己作一车队
            if mark[i] is None:
                mark[i] = i

        end = [None for _ in range(n)]
        for i in range(n)[::-1]:#每个车队寻找一个唯一标记
            if mark[i] == i:
                end[i] = i
            else:
                end[i] = end[mark[i]]

        return len(set(end))
        
target = 12
position = [10,8,0,5,3]
speed = [2,4,1,1,3]
print(Solution.carFleet('self',target,position,speed))