class Solution:
    def minChanges(self, s: str) -> int:
        str_half = len(s) // 2
        changes = 0
        for i in range(str_half):
          if s[i * 2] != s[i * 2 + 1]:
            changes += 1
        return changes