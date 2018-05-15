class Solution:
    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        par=[-1]*N
        siz=[0]*N
        dis=[0]*N
        if edges==[]:return dis
        e={}
        for i in range(len(edges)): #建立无向图
            if edges[i][0] not in e:
                e[edges[i][0]]=[]
            if edges[i][1] not in e:
                e[edges[i][1]]=[]
            e[edges[i][0]].append(edges[i][1])
            e[edges[i][1]].append(edges[i][0])

        def dfs(u):
            siz[u]=1 #siz为以自身为根的树的节点数
            dis[u]=0 #dis为以自身为根的树的各节点距离之和
            for v in e[u]: #寻找通路
                if par[u]==v:continue #形成回路
                par[v]=u #记录扩散的源头
                dfs(v) #路搜索
                siz[u]+=siz[v] #节点数增加
                dis[u]+=siz[v]+dis[v] #距离之和增加

        dfs(0)
        #print(list(range(6)),par,siz,dis,sep='\n')
        ans=[0]*N
        def dfs2(u):
            if par[u]==-1: #根节点
                ans[u]=dis[u]
            else: #转动一下树，把u当作根节点，得出式如下
                ans[u]=ans[par[u]]+N-2*siz[u]
            for v in e[u]: #按通路遍历赋值
                if par[u]==v:continue
                dfs2(v)

        dfs2(0)
        #print(ans)
        return ans