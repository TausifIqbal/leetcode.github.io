// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // there is a cooldown time of n 

        // in window put one 

        map<char,int> val;
        for(auto ch: tasks){
            val[ch]++;
        }
        priority_queue<int,vector<int>,less<int>> pq;
        for(auto itr=val.begin() ;itr!=val.end();itr++){
            pq.push(itr->second);
        }
        int ans=0;
        while(!pq.empty()){
            vector<int> tmp;
            int cnt=0;
            for(int i=0;i<(n+1) && !pq.empty();i++){
                    int x=pq.top();
                    pq.pop();
                    if(x>1){
                        tmp.emplace_back(x-1);
                    }
                    cnt++;
            }
            if(! tmp.empty() ){
                for(int x: tmp){
                    pq.push(x);
                }
                ans+= (n+1);
            }else{
                ans += cnt;
            }

        }
        return ans;
    }
};
