https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
// 1 2 3

    vector<int> get_next_smaller_ele(vector<int> heights){
        stack<int> mis;
        int n=heights.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!mis.empty() && heights[mis.top()] > heights[i]){
                int id = mis.top();
                mis.pop();
                ans[id]=i;
            }
            mis.push(i);
        }
        return ans;
    }
// 1 2 3
    vector<int> get_prev_smaller_ele(vector<int> heights){
        stack<int> mis;
        int n=heights.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!mis.empty() && heights[mis.top()] > heights[i]){
                mis.pop();
            }
            if(!mis.empty()){
                int id = mis.top();
                ans[i]=id;
            }
            mis.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev= get_prev_smaller_ele(heights);
        vector<int> next = get_next_smaller_ele(heights);
        int ans=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                next[i]=n;
            }
            int l = (next[i]-1) -  (prev[i]+1) +1;
            int area= l*heights[i];
            ans = max(area,ans);
        }
        return ans;
    }
};
