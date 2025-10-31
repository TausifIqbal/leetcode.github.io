// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
       // maximum working time with one worker is sum(jobs)
       // minimum possible maximum working time of two worker
       //   (knapsack)
       // minimum possible maximum working time of n worker
       //   (subset)
        int n=jobs.size();
        int INF=1e9+7;
        vector<int> dp1(1<<n+1,INF);
        vector<int> dp(1<<n+1,INF);
        // initialize
        for(int mask=1;mask<(1<<n);mask++){
            int time=0;
            for(int ii=0;ii<n;ii++){
                if(mask &(1<<ii)){
                    time += jobs[ii];
                }
            }
            dp[mask]= time;
        }
        dp1=dp;
        for(int i=2;i<=k;i++){
            vector<int> tmp(1<<n+1,INF);
            for(int mask=1;mask<(1<<n);mask++){
                tmp[mask] = dp[mask];
                for(int submask=mask;submask;submask= (submask-1)&mask){
                    tmp[mask]= min(tmp[mask], max(dp[submask^mask], dp1[submask]));
                }
            }
            dp=tmp;
        }

        return dp[(1<<n)-1];
    }
};
