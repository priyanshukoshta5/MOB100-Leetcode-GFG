class Solution:
    def minWindow(self, s: str, t: str) -> str:
        freq = collections.Counter(t)
        count = len(freq)
        i = j = 0
        ans = inf
        found = False
        start = 0
        last = len(s)-1
        while j<len(s):
            if s[j] in freq:
                freq[s[j]] -= 1
                if freq[s[j]]==0:
                    count = count-1
            if count>0:
                j = j+1
            elif count==0:
                found = True
                while count==0:
                    if (j-i+1)<ans:
                        ans = (j-i+1)
                        start = i
                    if s[i] in freq:
                        freq[s[i]] += 1
                        if freq[s[i]]==1:
                            count = count+1
                    i = i+1
                j = j+1
            # print(var, ans)
        if found:
            return s[start:start+ans]
        return ''