class Solution:
    def getMaximumXor(self, nums: list[int], maximumBit: int) -> list[int]:
        mask = 2 ** maximumBit - 1
        result_list = []
        cumulative_result = 0
        for num in nums:
            cumulative_result ^= num
            result_list.append(cumulative_result ^ mask)
        result_list.reverse()
        return result_list