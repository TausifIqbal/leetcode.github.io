//https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        
        // dp[i][j] --> minimum time to reach jth road with at most ith skip 
        int n=dist.size();
        int INF=1e9+7;
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,INF));
        dp[0][0]=0;
        for(int j=1;j<=n;j++){
            for(int i=0;i<=j;i++){
                // no skip
                if(dp[i][j-1]!=INF){
                    long long val = dp[i][j-1] + dist[j-1];
                    if(j!=n) val = ((val+speed-1)/speed)*speed;
                    dp[i][j] = min(dp[i][j], val);
                }
                // skip
                if( i>0 && dp[i-1][j-1]!=INF){
                    dp[i][j]=min(dp[i][j] , dp[i-1][j-1]+dist[j-1]);
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(dp[i][n]<= 1LL*hoursBefore*speed ){
                return i;
            }
        }
        return -1;

    }
};
