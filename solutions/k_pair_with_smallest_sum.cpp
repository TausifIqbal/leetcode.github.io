// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // num[i+1]+num[j+1] , num[i+1]+num[j], num[i]+num[j+1]
        map<array<int,2>,bool> vis;
        priority_queue< array<int,3>, vector<array<int,3>>, greater<array<int,3>> >pq;
        vector<vector<int>> ans;
        pq.push({nums1[0]+nums2[0],0,0});
        int n = nums1.size();
        int m = nums2.size();
        while(true){
            
            auto [sm,i,j] = pq.top();
            pq.pop();
            if(i+1<n){
                if(vis.count({i+1,j})==0){
                    pq.push({nums1[i+1]+nums2[j],i+1,j});
                    vis[{i+1,j}]=true;
                }
            }
            if(j+1<m){
                if(vis.count({i,j+1})==0){
                    pq.push({nums1[i]+nums2[j+1],i,j+1});
                    vis[{i,j+1}]=true;
                }
            }
            if(i+1<n && j+1<m){
                if(vis.count({i+1,j+1}) == 0){
                    pq.push({nums1[i+1]+nums2[j+1],i+1,j+1});
                    vis[{i+1,j+1}]=true;
                }
            }
            ans.push_back({nums1[i],nums2[j]});
            if(ans.size()==k){
                break;
            }
        }

        return ans;


    }
};
