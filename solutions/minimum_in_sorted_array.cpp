// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int ans=nums[0];

        while(l<=r){
            int m = (r-l)/2+l;
            if(nums[m]>=nums[0]){
                // if m is first half
                l=m+1;
            }else{
                // if m is 2nd half
                // minimum will be here 
                    ans=nums[m];
                    r=m-1;
            
            }
            
        }

        return ans;
    }
};
