class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        
        vector<int> netShifts(n + 1, 0); // Use a single array for net shifts
        for(auto shift : shifts) 
        {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            if(dir == 0)   // Backward shift
            { 
                netShifts[start]--;
                netShifts[end + 1]++;
            } 
            else            // Forward shift
            {        
                netShifts[start]++;
                netShifts[end + 1]--;
            }
        }

        string ans = s;
        int shift = 0;
        for(int i = 0; i < n; i++) 
        {
            shift += netShifts[i];
            int pos = ((ans[i] - 'a') + (shift % 26) + 26) % 26; // Ensure non-negative mod
            ans[i] = char('a' + pos);
        }

        return ans;
    }
};