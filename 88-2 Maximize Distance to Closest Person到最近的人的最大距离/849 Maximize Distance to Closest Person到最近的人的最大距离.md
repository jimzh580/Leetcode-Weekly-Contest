# In a row of seats, 1 represents a person sitting in that seat, 
# and 0 represents that the seat is empty. 
# There is at least one empty seat, and at least one person sitting.
# Alex wants to sit in the seat such that the distance between him 
# and the closest person to him is maximized. 
# Return that maximum distance to closest person.
# Example 1:
# Input: [1,0,0,0,1,0,1]
# Output: 2
# Explanation: 
# If Alex sits in the second open seat (seats[2]), 
# then the closest person has distance 2.
# If Alex sits in any other open seat, the closest person has distance 1.
# Thus, the maximum distance to the closest person is 2.
# Example 2:
# Input: [1,0,0,0]
# Output: 3
# Explanation: 
# If Alex sits in the last seat, the closest person is 3 seats away.
# This is the maximum distance possible, so the answer is 3.
# Note:
# 1 <= seats.length <= 20000
# seats contains only 0s or 1s, at least one 0, and at least one 1.

# 在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。
# 至少有一个空座位，且至少有一人坐在座位上。
# 亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
# 返回他到离他最近的人的最大距离。
# 示例 1：
# 输入：[1,0,0,0,1,0,1]
# 输出：2
# 解释：
# 如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
# 如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
# 因此，他到离他最近的人的最大距离是 2 。 
# 示例 2：
# 输入：[1,0,0,0]
# 输出：3
# 解释： 
# 如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
# 这是可能的最大距离，所以答案是 3 。
# 提示：
# 1 <= seats.length <= 20000
# seats 中只含有 0 和 1，至少有一个 0，且至少有一个 1。