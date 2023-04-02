class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int median = (n+m)/2;
        if((n+m)%2 == 0)
            median--;
        
        int i = 0, j = 0, ans = 0, left = 0;
        while(median>=0 && i<n && j<m)
        {
            if(nums1[i] <= nums2[j])
            {
                ans = nums1[i];
                i++;
            }
            else
            {
                ans = nums2[j];
                j++;
            }
            median--;
        }
        while(median >= 0 && i<n)
        {
            ans = nums1[i];
            i++;
            median--;
        }
        while(median >= 0 && j<m)
        {
            ans = nums2[j];
            j++;
            median--;
        }
        
        if((n+m)%2 == 1)
            return ans;
        else
        {
            int next;
            if(i<n && j<m)
                next = min(nums1[i], nums2[j]);
            else if(i<n)
                next = nums1[i];
            else if(j<m)
                next = nums2[j];
            return ((double)ans + (double)next)/ 2;
        }
        return -1;
    }
};