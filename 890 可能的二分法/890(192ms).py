class Solution:
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        edges = [[] for i in range(N)]
        for pair in dislikes:#建立无向图
            edges[pair[0]-1].append(pair[1]-1)
            edges[pair[1]-1].append(pair[0]-1)
        
        team = [-1 for i in range(N)]
        for i, p in enumerate(team):
            if p == -1:#还未组
                team[i] = 0
                q = collections.deque()
                q.append(i)
                while len(q):
                    pre = q.popleft()
                    for j in edges[pre]:#不喜匹配的节点中
                        if team[j] == -1:#未组
                            team[j] = 1 - team[pre]#分给另一组
                            q.append(j)
                        elif team[j] == team[pre]:#组成了同一队
                            return False
        return True