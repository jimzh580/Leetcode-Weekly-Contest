class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        self.p = (0, 0)
        self.d = (0, 1)
        self.r = 0
        self.obstacles = set(tuple(obstacle) for obstacle in obstacles)
        for command in commands:
            if command == -2: self.turnLeft()
            elif command == -1: self.turnRight()
            else: self.move(command)
        return self.r
    def turnLeft(self): self.d = (-self.d[1], self.d[0])
    def turnRight(self): self.d = (self.d[1], -self.d[0])
    def move(self, steps):
        for _ in xrange(steps):
            nextp = tuple(a+b for a,b in zip(self.p,self.d))
            if nextp not in self.obstacles: self.p = nextp
            else: break
        self.r = max(self.r, sum(d**2 for d in self.p))