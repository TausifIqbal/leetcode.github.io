//https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mds;
        int n=temperatures.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){

            while(!mds.empty() && temperatures[mds.top()] < temperatures[i]){
                int id= mds.top();
                mds.pop();
                ans[id]=i;
            }
            mds.push(i);
        }
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                ans[i]=0;
            }else{
                ans[i]=ans[i]-i;
            }
        }
        return ans;
    }

};
