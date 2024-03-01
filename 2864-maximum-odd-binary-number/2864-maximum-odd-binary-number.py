class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        one = s.count('1')
        return '1'*(one - 1) + '0'*(len(s) - one) + '1'