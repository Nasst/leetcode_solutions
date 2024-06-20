import 'dart:math';

// Alright, this time I'll admit I looked at the solution.
// For some reason or another, binary search didn't cross my mind.
// My code worked, but badly lacked performance, even after several optimizations

class Solution {
  int bouquetsByDay(List<int> bloomDay, int currentDay, int flowersPerBouquet) {
    var bouquets = 0;
    var currentFlowers = 0;
    for (var i = 0; i < bloomDay.length; i++) {
      if (bloomDay[i] > currentDay) {
        currentFlowers = 0;
      } else {
        currentFlowers++;
        if (currentFlowers == flowersPerBouquet) {
          bouquets++;
          currentFlowers = 0;
        }
      }
    }
    return bouquets;
  }

  int minDays(List<int> bloomDay, int m, int k) {
    var maxVal = bloomDay.reduce(max);
    var minVal = 0;
    var answer = -1;
    while (maxVal >= minVal) {
      var midPoint = (minVal + maxVal) ~/ 2;
      var currentBouquets = bouquetsByDay(bloomDay, midPoint, k);
      if (currentBouquets >= m) {
        answer = midPoint;
        maxVal = midPoint - 1;
      } else {
        minVal = midPoint + 1;
      }
    }
    return answer;
  }
}


// MY OLD CODE

// import 'dart:collection';
// import 'dart:math';

// class Solution {
//   final memoTable2 = <int, Map<int, int>>{};
//   final memoTable = <List<int>>[];
//   final bouquetList = <int>[];

//   void calcBouquetList(List<int> bloomDay, int flowerNum) {
//     if (flowerNum > bloomDay.length) return;
//     var currBouquet = SplayTreeMap<int, int>();
//     //build first bouquet
//     for (var i = 0; i < flowerNum; i++) {
//       if (currBouquet[bloomDay[i]] == null) {
//         currBouquet[bloomDay[i]] = 1;
//       } else {
//         currBouquet[bloomDay[i]] = currBouquet[bloomDay[i]]! + 1;
//       }
//     }
//     bouquetList.add(currBouquet.lastKey()!);
//     for (var i = flowerNum; i < bloomDay.length; i++) {
//       var droppingFlower = bloomDay[i - flowerNum];
//       currBouquet[droppingFlower] = currBouquet[droppingFlower]! - 1;
//       if (currBouquet[droppingFlower]! == 0) {
//         currBouquet.remove(droppingFlower);
//       }
//       var addingFlower = bloomDay[i];
//       if (currBouquet[addingFlower] == null) {
//         currBouquet[addingFlower] = 1;
//       } else {
//         currBouquet[addingFlower] = currBouquet[addingFlower]! + 1;
//       }
//       bouquetList.add(currBouquet.lastKey()!);
//     }
//   }

//   int minDays(List<int> bloomDay, int m, int k) {
//     calcBouquetList(bloomDay, k);
//     var maxDay = 1;
//     var bouquetNum = 1;
//     for (var i = 0; i < k + 1; i++) {
//       memoTable.add(List.filled(m + 1, -1));
//       memoTable[i][0] = 0;
//     }
//     while (maxDay <= bloomDay.length) {
//       if (bouquetNum * k > maxDay || bouquetNum > m) {
//         maxDay++;
//         bouquetNum = 1;
//       } else {
//         var ignoreThisFlower = memoTable[(maxDay - 1) % (k + 1)][bouquetNum];
//         var includeThisFlower = max(
//             memoTable[(maxDay - k) % (k + 1)][bouquetNum - 1],
//             bouquetList[maxDay - k]);
//         if (ignoreThisFlower == -1) {
//           memoTable[maxDay % (k + 1)][bouquetNum] = includeThisFlower;
//         } else {
//           memoTable[maxDay % (k + 1)][bouquetNum] =
//               min(ignoreThisFlower, includeThisFlower);
//         }
//         bouquetNum++;
//       }
//     }
//     return memoTable[bloomDay.length % (k + 1)][m];
//   }
// }