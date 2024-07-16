# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if (not head) or (not head.next):
            return head

        n = 0
        temp = head
        while(temp.next):
            temp = temp.next
            n+=1

        k = k % (n+1)
        temp.next = head
        
        temp = head
        for i in range(n-k):
            temp = temp.next

        head = temp.next
        temp.next = None

        return head