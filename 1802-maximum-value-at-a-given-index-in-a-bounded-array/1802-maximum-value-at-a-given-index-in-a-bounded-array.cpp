class Solution {
private:
    bool isValid(long long mid, int n, int index, int maxSum){
        long long sum = (mid * (mid - 1)) / 2;      // Sum on Left/Right keeping mid as Peak element
        long long leftSum = sum, rightSum = sum;

        long long left = index - 1;     // Elements on left
        if((mid - 1) > left)    // If there are less elements in left than (mid-1), so we need to add the remaining elements sum
        {
            long long diff = (mid-1) - left;    // extra elements on left
            leftSum -= (diff * (diff + 1)) / 2;
        }
        else if(left > (mid - 1))     // Adding remaining elements as '1' on left
            leftSum += (left - (mid - 1)); 

        long long right = n - index;    // Elements on Right
        if((mid - 1) > right)   // If there are less elements in right than (mid-1), so we need to add the remaining elements sum
        {
            long long diff = (mid-1) - right;   // extra elements on right
            rightSum -= (diff * (diff + 1)) / 2;
        }
        else if(right > (mid - 1))      // Adding remaining elements as '1' on right
            rightSum += (right - (mid - 1)); 

        return (leftSum + rightSum) <= (maxSum - mid);
    }

public:
    int maxValue(int n, int index, int maxSum) {
        index = index + 1;  // As we will be using array as 1 indexed;
        int low = 1, high = maxSum;     // Range of search space [1, maxSum]
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(isValid(mid, n, index, maxSum))
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};