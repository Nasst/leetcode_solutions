# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
          return None
        if not head.next:
          return head
        new_start = head.next
        while head and head.next:
          first = head
          second = first.next
          third = second.next
          second.next = first
          first.next = third.next if third and third.next else third
          head = third
        return new_start
