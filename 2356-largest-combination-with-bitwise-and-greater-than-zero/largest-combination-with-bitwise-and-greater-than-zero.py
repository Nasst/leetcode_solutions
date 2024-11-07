class Solution:
    def largestCombination(self, candidates: list[int]) -> int:
        mask = 2 ** 25
        set_list = []
        while mask > 0:
            set_list.append(set())
            for i, candidate in enumerate(candidates):
                if candidate & mask != 0:
                    set_list[-1].add(i)
            mask >>= 1
        largest_set = max(*set_list, key=len)
        return len(largest_set)