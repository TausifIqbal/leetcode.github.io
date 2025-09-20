// https://leetcode.com/problems/contiguous-array/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int running_sum=0;
        mp[0]=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int val = (num==1)?num:-1;
            running_sum +=val;
            if(mp.count(running_sum)){
                ans = max(i-mp[running_sum],ans);;
            }else{
                mp[running_sum] = i;
            }

        }
        return ans;

    }
};

// Time Complexity O(n)
// Space Complexity O(n)
// for imporved runtime use vector of len 2*len+1 as a map 
