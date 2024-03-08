class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = collections.Counter(nums)
        maxFreq = max(list(freq.values()))
        return len([i for i in freq.values() if i == maxFreq]) * maxFreq