import 'dart:collection';
import 'dart:math';

class Solution {
  int maxProfitAssignment(
      List<int> difficulty, List<int> profit, List<int> worker) {
    worker.sort();
    var jobMap = SplayTreeMap<int, int>();
    for (var i = 0; i < difficulty.length; i++) {
      if (jobMap.containsKey(difficulty[i])) {
        jobMap[difficulty[i]] = max(jobMap[difficulty[i]]!, profit[i]);
      } else {
        jobMap[difficulty[i]] = profit[i];
      }
    }
    var currentKey = jobMap.firstKey();
    var currentMaxProfit = jobMap[currentKey!]!;
    while (currentKey != null) {
      currentMaxProfit = max(currentMaxProfit, jobMap[currentKey]!);
      jobMap[currentKey] = currentMaxProfit;
      currentKey = jobMap.firstKeyAfter(currentKey);
    }
    var currentProfitTotal = 0;
    for (var currWorker in worker) {
      var workDifficulty = jobMap.lastKeyBefore(currWorker + 1);
      if (workDifficulty != null) {
        currentProfitTotal += jobMap[workDifficulty]!;
      }
    }
    return currentProfitTotal;
  }
}