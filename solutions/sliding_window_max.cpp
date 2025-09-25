// https://leetcode.com/problems/sliding-window-median/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        // dq   small ... large
        for(int i=0;i<n;i++){
          
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
                
            // reduce size to k
            if(i>=k && dq.front() <= i-k){
                // remove i-kth index
                dq.pop_front();

            }
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
