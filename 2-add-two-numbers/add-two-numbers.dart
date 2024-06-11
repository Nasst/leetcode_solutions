class Solution {
  BigInt listNodeToInt(ListNode? l1) {
    var currentBase = BigInt.from(1);
    var result = BigInt.from(0);
    while (l1 != null) {
      result += BigInt.from(l1.val) * currentBase;
      currentBase *= BigInt.from(10);
      l1 = l1.next;
    }
    return result;
  }

  // i has to be larger than 0
  ListNode intToListNode(BigInt i) {
    var firstNode = ListNode();
    firstNode.val = (i % BigInt.from(10)).toInt();
    i ~/= BigInt.from(10);
    ListNode movingNode = firstNode;
    while (i > BigInt.from(0)) {
      movingNode.next = ListNode();
      movingNode = movingNode.next!;
      movingNode.val = (i % BigInt.from(10)).toInt();
      i ~/= BigInt.from(10);
    }
    return firstNode;
  }

  ListNode? addTwoNumbers(ListNode? l1, ListNode? l2) {
    return intToListNode(listNodeToInt(l1) + listNodeToInt(l2));
  }
}