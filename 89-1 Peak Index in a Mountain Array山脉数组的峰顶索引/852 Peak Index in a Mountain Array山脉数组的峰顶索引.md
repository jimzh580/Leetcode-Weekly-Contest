# Let's call an array A a mountain if the following properties hold:
# A.length >= 3
# There exists some 0 < i < A.length - 1 such that 
# A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
# Given an array that is definitely a mountain, 
# return any i such that 
# A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
# Example 1:
# Input: [0,1,0]
# Output: 1
# Example 2:
# Input: [0,2,1,0]
# Output: 1
# Note:
# 3 <= A.length <= 10000
# 0 <= A[i] <= 10^6
# A is a mountain, as defined above.

# 我们把符合下列属性的数组 A 称作山脉：
# A.length >= 3
# 存在 0 < i < A.length - 1 使得
# A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
# 给定一个确定为山脉的数组，
# 返回任何满足 
# A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。
# 示例 1：
# 输入：[0,1,0]
# 输出：1
# 示例 2：
# 输入：[0,2,1,0]
# 输出：1
# 提示：
# 3 <= A.length <= 10000
# 0 <= A[i] <= 10^6
# A 是如上定义的山脉