class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        xx=collections.defaultdict(list)
        yy=collections.defaultdict(list)
        for i in obstacles:
            xx[i[0]].append(i[1])
            yy[i[1]].append(i[0])
        to=1
        x=y=0
        maxn=0
        for i in commands:
            if i==-1:
                to+=1
                if to>4:to=1
            elif i==-2:
                to-=1
                if to<1:to=4
            else:
                tox=x
                toy=y
                if to==1:
                    toy=y+i
                    for j in range(y+1,y+i+1):
                        if j in xx[x]:
                            toy=j-1
                            break
                elif to==2:
                    tox=x+i
                    for j in range(x+1,x+i+1):
                        if j in yy[y]:
                            tox=j-1
                            break
                elif to==3:
                    toy=y-i
                    for j in range(y-1,y-i-1,-1):
                        if j in xx[x]:
                            toy=j+1
                            break
                elif to==4:
                    tox=x-i
                    for j in range(x-1,x-i-1,-1):
                        if j in yy[y]:
                            tox=j+1
                            break
                x=tox
                y=toy
                maxn=max(maxn,x**2+y**2)
        return maxn