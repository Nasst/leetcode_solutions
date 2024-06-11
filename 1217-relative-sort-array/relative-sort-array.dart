class Solution {
  List<int> relativeSortArray(List<int> arr1, List<int> arr2) {
    var numCount = <int, int>{};
    for (var num in arr2) {
      numCount[num] = 0;
    }
    var leftovers = <int>[];
    for (var num in arr1) {
      if (numCount.containsKey(num)) {
        numCount[num] = numCount[num]! + 1;
      } else {
        leftovers.add(num);
      }
    }
    var resultList = <int>[];
    numCount.forEach((key, value) {
      for (var i = 0; i < value; i++) {
        resultList.add(key);
      }
    });
    leftovers.sort();
    resultList.addAll(leftovers);
    return resultList;
  }
}