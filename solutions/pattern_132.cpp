// https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 3 5 0 4 3
        //  

        // 1 2 3 
        // 2 --> largest 
        // 1 ---> smallest 
        // 3 --> middle

       
        int third = INT_MIN;
        stack<int> second;
        int n=nums.size();
        // we are population 2nd then third
        for(int i=n-1;i>=0;i--){
            if(nums[i] < third){ // num[i] can be one
                return true;
            }
            while( !second.empty() && nums[i] > second.top()){
                third = second.top();
                second.pop();
            }
            second.push(nums[i]);
        }
        return false;
    }
};
