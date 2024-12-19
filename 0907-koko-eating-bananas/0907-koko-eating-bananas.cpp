class Solution {
public:
    bool canEat(const vector<int>& piles, int m, int h) {
        long long hours = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            hours += (piles[i] + m - 1) / m; // Efficient ceiling calculation
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEat(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};