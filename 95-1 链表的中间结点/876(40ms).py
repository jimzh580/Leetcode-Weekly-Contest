# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:return None
        fast=slow=head
        while fast.next and fast.next.next:
            fast=fast.next.next
            slow=slow.next
        if fast.next:
            slow=slow.next
        return slow