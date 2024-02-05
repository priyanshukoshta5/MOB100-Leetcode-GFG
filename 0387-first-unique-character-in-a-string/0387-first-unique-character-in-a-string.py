class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = collections.Counter(s)
        for i in range(len(s)):
            if freq[s[i]] == 1:
                return i
        return -1