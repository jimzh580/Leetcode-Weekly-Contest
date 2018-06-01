class Solution:
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        n=len(rooms)
        visit=[]
        def find(rooms,visit,k):
            for i in rooms[k]:
                if i not in visit:
                    visit.append(i)
                    find(rooms,visit,i)
        find(rooms,visit,0)
        for i in range(1,n):
            if i not in visit:
                return False
        return True
        
rooms=[[]]
print(Solution.canVisitAllRooms('self',rooms))