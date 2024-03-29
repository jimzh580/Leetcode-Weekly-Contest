# Let's call any (contiguous) subarray B (of A) a mountain 
# if the following properties hold:
# B.length >= 3
# There exists some 0 < i < B.length - 1 
# such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
# (Note that B could be any subarray of A, including the entire array A.)
# Given an array A of integers, return the length of the longest mountain. 
# Return 0 if there is no mountain.
# Example 1:
# Input: [2,1,4,7,3,2,5]
# Output: 5
# Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
# Example 2:
# Input: [2,2,2]
# Output: 0
# Explanation: There is no mountain.
# Note:
# 0 <= A.length <= 10000
# 0 <= A[i] <= 10000

# 我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
# B.length >= 3
# 存在 0 < i < B.length - 1 使得 
# B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
# （注意：B 可以是 A 的任意子数组，包括整个数组 A。）
# 给出一个整数数组 A，返回最长 “山脉” 的长度。
# 如果不含有 “山脉” 则返回 0。
# 示例 1：
# 输入：[2,1,4,7,3,2,5]
# 输出：5
# 解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
# 示例 2：
# 输入：[2,2,2]
# 输出：0
# 解释：不含 “山脉”。
# 提示：
# 0 <= A.length <= 10000
# 0 <= A[i] <= 10000