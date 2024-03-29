# In a group of N people (labelled 0, 1, 2, ..., N-1), 
# each person has different amounts of money, 
# and different levels of quietness.
# For convenience, we'll call the person with label x, simply "person x".
# We'll say that richer[i] = [x, y] 
# if person x definitely has more money than person y.  
# Note that richer may only be a subset of valid observations.
# Also, we'll say quiet[x] = q if person x has quietness q.
# Now, return answer, 
# where answer[x] = y if y is the least quiet person 
# (that is, the person y with the smallest value of quiet[y]), 
# among all people who definitely have equal to or more money than person x.
# Example 1:
# Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], 
# quiet = [3,2,5,4,6,1,7,0]
# Output: [5,5,2,5,4,5,6,7]
# Explanation: 
# answer[0] = 5.
# Person 5 has more money than 3, which has more money than 1, 
# which has more money than 0.
# The only person who is quieter (has lower quiet[x]) is person 7, but
# it isn't clear if they have more money than person 0.
# answer[7] = 7.
# Among all people that definitely have equal to or more money than person 7
# (which could be persons 3, 4, 5, 6, or 7), 
# the person who is the quietest (has lower quiet[x])
# is person 7.
# The other answers can be filled out with similar reasoning.
# Note:
# 1 <= quiet.length = N <= 500
# 0 <= quiet[i] < N, all quiet[i] are different.
# 0 <= richer.length <= N * (N-1) / 2
# 0 <= richer[i][j] < N
# richer[i][0] != richer[i][1]
# richer[i]'s are all different.
# The observations in richer are all logically consistent.

# 在一组 N 个人（编号为 0, 1, 2, ..., N-1）中，
# 每个人都有不同数目的钱，以及不同程度的安静（quietness）。
# 为了方便起见，我们将编号为 x 的人简称为 "person x "。
# 如果能够肯定 person x 比 person y 更有钱的话，
# 我们会说 richer[i] = [x, y] 。注意 richer 可能只是有效观察的一个子集。
# 另外，如果 person x 的安静程度为 q ，我们会说 quiet[x] = q 。
# 现在，返回答案 answer ，其中 answer[x] = y 的前提是，
# 在所有拥有的钱不少于 person x 的人中，person y 是最喧闹的人
# （也就是安静值 quiet[y] 最小的人）。
# 示例：
# 输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], 
# quiet = [3,2,5,4,6,1,7,0]
# 输出：[5,5,2,5,4,5,6,7]
# 解释： 
# answer[0] = 5，
# person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，
# person 1 比 person 0 有更多的钱。
# 唯一喧闹（有较低的安静值 quiet[x]）的人是 person 7，
# 但是目前还不清楚他是否比 person 0 更有钱。
# answer[7] = 7，
# 没有人比 person 7 更喧闹，所以 person 7 是最喧闹的人。
# 所以在拥有的钱不少于 person 7 的人中最喧闹的就是他自己。
# 其他的答案也可以用类似的推理来解释。
# 提示：
# 1 <= quiet.length = N <= 500
# 0 <= quiet[i] < N，所有 quiet[i] 都不相同。
# 0 <= richer.length <= N * (N-1) / 2
# 0 <= richer[i][j] < N
# richer[i][0] != richer[i][1]
# richer[i] 都是不同的。
# 对 richer 的观察在逻辑上是一致的。