//https://leetcode.com/problems/maximum-number-of-robots-within-budget

class Solution {
public:
    vector<long long> sum;

    bool ok(vector<int>& chargeTimes,vector<int>&runningCosts,long long budget,int k){
        if(k==0){
            return true;
        }
        // max in running window k 
        // sum of window k
        deque<int > dq;
        int n= chargeTimes.size();
        for(int i=0;i<n;i++){
            while(!dq.empty() && chargeTimes[dq.back()]<=chargeTimes[i]){
                dq.pop_back();
            }
            dq.push_back(i); 
            if(dq.front() <= i-k){
                dq.pop_front();
            }
            
            if(i>= k-1){ 
                long long optimal_cost = k*(sum[i+1]-sum[i-k+1]) + chargeTimes[dq.front()];
                if(optimal_cost <= budget){
                    return true;
                }
            }
        }
        return false;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
         
        int n = runningCosts.size();
        int l=0,r=n;
        int ans=0;
        sum.resize(n+1,0);
        for(int i=0;i<n;i++){
            sum[i+1] = runningCosts[i] + sum[i];
        }
        // return 1;
        while(l<=r){
            int m=(r-l)/2 +l;
            if(ok(chargeTimes,runningCosts,budget,m)){
                ans = m;
                l = m+1;
            }else{
                r = m -1;
            }
        }
        return ans;
    }
};
