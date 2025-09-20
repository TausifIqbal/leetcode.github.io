//https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0],fast=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                // cycle found
                break;
            }
        }

        // find start of cycle
        int start=nums[0];
        while(start!=slow){
            start=nums[start];
            slow = nums[slow];
        }
        return start;
    }
};
