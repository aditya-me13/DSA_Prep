# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        
        def reverseLL(head):
            dummy = None
            temp = head
            while(head):
                temp = head.next
                head.next = dummy
                dummy = head
                head = temp
            return dummy
        
        def move_forward(ptr, k):
            for i in range(k):
                ptr = ptr.next
            return ptr
        
        ptr = head
        count = 0
        while(ptr):
            ptr = ptr.next
            count += 1
        
        count = count//k

        
        temp = ListNode(0)
        temp.next = head

        for i in range(count):
            dummy = temp
            itr = dummy.next
            
            temp = move_forward(temp, k)
            ptr = temp.next
            temp.next = None

            dummy.next = reverseLL(dummy.next)
            itr.next = ptr
            if(itr == head):
                head = dummy.next
                
            temp = itr
            
        return head

