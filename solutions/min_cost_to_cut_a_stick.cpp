// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    map<array<int,2>,int> mp;
    int solve(int i, int j,vector<int>& cuts){
        if(i==j){
            return 0;
        }
        if(mp.count({i,j})){
            return mp[{i,j}];
        }
        int best=1e9+7;
        bool have_cut=false;
        for(int cut: cuts){
            if(cut>i && cut<j){
                have_cut=true;
                best= min(solve(i,cut,cuts)+solve(cut,j,cuts)+j-i,best);
            }
        }
        if(!have_cut){
            best=0;
        }
        mp[{i,j}]=best;
        return best; 
    }
    int minCost(int n, vector<int>& cuts) {
        // cut[i....j] = cut[i..k] + cut[k.....j];
        int ans = solve(0,n,cuts);
        return ans;
    }
};
