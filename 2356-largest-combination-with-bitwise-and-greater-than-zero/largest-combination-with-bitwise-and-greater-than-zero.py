class Solution:
    def largestCombination(self, candidates: list[int]) -> int:
        mask = 2 ** 25
        max_num = 0
        while mask > 0:
            current = 0
            for candidate in candidates:
                if candidate & mask != 0:
                    current += 1
            max_num = max(max_num, current)
            mask >>= 1
        return max_num