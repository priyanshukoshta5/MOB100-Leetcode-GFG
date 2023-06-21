class Solution {
    
    // Function to calculate the cost making all elements equal to "mid"
    long long getCost(vector<int> &nums, int mid, vector<int>& cost){
        long long totalCost = 0;
        for(int i = 0; i < nums.size(); i++)
            totalCost += (1LL * abs(nums[i] - mid)) * (1LL * cost[i]);
        return totalCost;
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        // Setting lower and higher boundaries of the Search Space
        int low = INT_MAX, high = INT_MIN;
        for(int i: nums)
        {
            low = min(low, i);
            high = max(high, i);
        }  
        
        // Trying to find the minimum of the Covex \/ function
        long long minCost = getCost(nums, low, cost);
        while(low <= high)
        {
            int mid = low + (high - low)/2;

            long long leftCost = getCost(nums, mid, cost);
            long long rightCost = getCost(nums, mid+1, cost);

            // When leftCost <= rightCost, we can say the minimum in on Left
            if(leftCost <= rightCost)   //  Move left
            {
                minCost = min(leftCost, minCost);
                high = mid - 1;
            }
            // When leftCost > rightCost, we can say the minimum in on Right
            else    // Move right;
            {
                minCost = min(rightCost, minCost);
                low = mid+1;
            }
        }

        return minCost;
    }
};