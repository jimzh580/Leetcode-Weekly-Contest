class Solution:
    def minRefuelStops(self, target, startFuel, stations):
        """
        :type target: int
        :type startFuel: int
        :type stations: List[List[int]]
        :rtype: int
        """
        d = collections.defaultdict(int)#记录油量
        d[0] = startFuel#初始油量
        for dist, fuel in stations:#距起点位置，可加油量
            dd = collections.defaultdict(int)
            stopsNum = 0
            while stopsNum in d:
                if d[stopsNum] >= dist:#是否可以经过该加油站
                    dd[stopsNum + 1] = d[stopsNum] + fuel #加油
                stopsNum += 1
            for i, j in d.items():
                dd[i] = max(d[i], dd[i])
            d = dd
        stopsNum = 0
        while stopsNum in d:
            if d[stopsNum] >= target:
                return stopsNum
            stopsNum += 1
        return -1