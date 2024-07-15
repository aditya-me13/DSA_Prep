# Problem Link: https://leetcode.com/problems/insertion-sort-list/description/

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        start = ListNode(-1)
        start.next = head

        curr = head
        prev = start

        while curr:
            if curr.next and curr.next.val < curr.val:
                while prev.next and prev.next.val < curr.next.val:
                    prev = prev.next
                
                # swap prev and curr
                temp = prev.next
                prev.next = curr.next
                curr.next = curr.next.next
                prev.next.next = temp

            else:
                curr = curr.next
            
            prev = start
        
        return start.next