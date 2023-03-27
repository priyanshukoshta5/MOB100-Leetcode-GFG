class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> leftmax(n,0);
        leftmax[0] = height[0];
        
        vector<int> rightmax(n,0);
        rightmax[n-1] = height[n-1];
        
        for(int i=1, j=n-2; i<n; i++, j--)
        {
            leftmax[i] = max(leftmax[i-1], height[i]);
            rightmax[j] = max(rightmax[j+1], height[j]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int k =  min(leftmax[i], rightmax[i]);
            if(height[i] < k)
                ans += (k-height[i]);
        }
        
        return ans;
    }
};