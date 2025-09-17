// https://leetcode.com/problems/climbing-stairs/description/


class Solution {
public:
    int climbStairs(int n) {
        array<int,2> ans{1,1}; // 0-->1, 1-->1
        for(int i=2;i<=n;i++){
            auto next = ans;
            next[1] = ans[1]+ans[0];
            next[0] = ans[1];

            ans = next;
        }
        return ans[1];
    }
};
