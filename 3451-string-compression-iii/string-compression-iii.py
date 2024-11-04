class Solution:
    def compressedString(self, word: str) -> str:
        counter = 0
        comp = ''
        last_char = ''
        for character in word:
          if last_char == character:
            counter += 1
            if counter == 9:
              comp += '9' + last_char
              last_char = ''
              counter = 0
          else:
            if counter != 0:
              comp += str(counter) + last_char
            counter = 1
            last_char = character
        comp += '' if counter == 0 else str(counter) + last_char
        return comp