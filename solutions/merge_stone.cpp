//https://leetcode.com/problems/minimum-cost-to-merge-stones/
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        
        int n=stones.size();
        if( (n-1) % (k-1)  !=0 ){
            return -1;
        }
        int INF=1e9+7;
        vector<int> p(n+1);
        for(int i=0;i<n;i++){
            p[i+1] = p[i]+stones[i]; // one-based index
        }
        vector<vector<int>> dp(n,vector<int>(n));

        // We start from a minimum length, len of K. Anything lesser, does not incur any cost.
        for(int len=k;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                dp[i][j]=INF;
                // merge stone from i to j
                // mid divides i-j into (1, rest), (K, rest), (2K-1, rest), etc....
                for(int mid=i;mid<j;mid+=k-1){
                    // The reason to calculate sub-problems which are not real merges, is to copy over the minimum of previous merge costs towards caculating the next real merge
                    dp[i][j]=min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
                }
                // The check (len-1 )% (K-1) == 0, signals a true merge and we calcuate the additional costs for this sub-problem.
                if( (j-i)%(k-1)==0 ){
                    dp[i][j] +=p[j+1]-p[i];
                } 
            }
        }

        return dp[0][n-1];

    }
};
