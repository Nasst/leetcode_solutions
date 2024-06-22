# I'm mad that there was no dart option. Probably not "pythonesque"

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        evenSegmentLengths = []
        consecutiveEven = 0
        solution = 0
        for num in nums:
            if num % 2 == 0:
                consecutiveEven += 1
            else:
                evenSegmentLengths.append(consecutiveEven)
                consecutiveEven = 0
        evenSegmentLengths.append(consecutiveEven)
        for i in range(k, len(evenSegmentLengths)):
            solution += (evenSegmentLengths[i] + 1) * (evenSegmentLengths[i - k] + 1)
        return solution