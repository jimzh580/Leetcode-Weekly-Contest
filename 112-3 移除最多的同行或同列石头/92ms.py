class Solution(object):
    def removeStones(self, stones):
        """
        :type stones: List[List[int]]
        :rtype: int
        """
        count_groups = 0
        n = len(stones)
        info_rows = {}
        info_cols = {}
        for (i,j) in stones:
            if i not in info_rows:
                info_rows[i] = []
            info_rows[i].append(j)
            if j not in info_cols:
                info_cols[j] = []
            info_cols[j].append(i)
            
        global_visited = set()
        for (i,j) in stones:
            if (i,j) in global_visited:
                continue
            local_visited = set()
            Q = [(i,j)]
            while Q:
                (k,l) = Q.pop()
                if (k,l) in local_visited:
                    continue
                local_visited.add((k,l))
                for lx in info_rows[k]:
                    Q.append((k,lx))
                for kx in info_cols[l]:
                    Q.append((kx,l))
            count_groups+=1
            global_visited.update(local_visited)
        return n-count_groups