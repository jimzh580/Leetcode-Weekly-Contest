from collections import deque

class Solution(object):
    def shortestPathAllKeys(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        si, sj = 0, 0
        n = len(grid) #行数
        m = len(grid[0]) #列数
        k = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '@':#记录起点
                    si, sj = i, j
                if grid[i][j] >= 'a' and grid[i][j] <= 'f':#记录钥匙数
                    k = max(k, ord(grid[i][j])-ord('a')+1)
        # print k
        keys = 0
        q = deque([(si, sj, 0, keys)])#起点入队列
        vis = set([(si, sj, keys)])#访问标记
        while q:#宽度搜索
            i, j, dst, keys = q.pop() #横坐标、纵坐标、步数、钥匙标记
            for di, dj in [(-1, 0), (1, 0), (0, 1), (0, -1)]:#四个方向
                ni, nj = i + di, j + dj #移动
                if ni < 0 or ni == n or nj < 0 or nj == m:#越界判断
                    continue
                if grid[ni][nj] == '#':#墙
                    continue
                if grid[ni][nj] >= 'A' and grid[ni][nj] <= 'F':#门，判断是否有钥匙
                    if (keys >> (ord(grid[ni][nj]) - ord('A'))) & 1 == 0:
                        continue
                nkeys = keys
                if grid[ni][nj] >= 'a' and grid[ni][nj] <= 'f':#钥匙，保存该钥匙
                    nkeys |= (1 << (ord(grid[ni][nj]) - ord('a')))
                    if nkeys == (1 << k) - 1:#所有钥匙已被获取，返回步数
                        return dst + 1
                if (ni, nj, nkeys) in vis:#是否访问过
                    continue
                q.appendleft((ni, nj, dst+1, nkeys))#入队尾
                vis.add((ni, nj, nkeys))#访问标记
        return -1