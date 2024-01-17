class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freq = collections.Counter(arr)
        temp = list(freq.values())
        temp.sort()
        # print(freq, temp)
        for i in range(1, len(temp)):
            if temp[i] == temp[i - 1]:
                return False
        return True