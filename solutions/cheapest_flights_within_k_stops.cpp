//https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<array<int,2>>> adj(n);
        for(auto flight: flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        queue<array<int,2>> q;
        int INF=1e9;
        vector<int> cost(n,INF);
        q.push({src,0}); // node,cost
        cost[src]=0;
        int hop=0;
        while(!q.empty() ){
            if(hop>k){
                break;
            }
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [v,vc]= q.front();
                q.pop();
                for(auto [u,c]: adj[v]){
                    if(cost[u]> vc+c){
                        cost[u]=vc+c;
                        q.push({u,vc+c});
                    }
                }
            }
            hop++;
        }
        
        int ans=cost[dst];
        return ans==INF?-1:ans;
    }
};
