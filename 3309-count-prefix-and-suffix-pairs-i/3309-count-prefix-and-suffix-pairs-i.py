class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)

        cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                # print(words[i], words[j][:len(words[i])], words[j][-1 * len(words[i]):])
                if i != j and len(words[i]) <= len(words[j]) and words[i] == words[j][:len(words[i])] and words[i] == words[j][-1 * len(words[i]):]:
                    cnt += 1

        return cnt