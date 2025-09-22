
// https://leetcode.com/problems/number-of-visible-people-in-a-queue/class 
public:

    vector<int> getNGE(vector<int>& heights){
        stack<int> mds;
        int n=heights.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!mds.empty() && heights[mds.top()] < heights[i] ){
                int id= mds.top();
                mds.pop();
                ans[id]=i;
            }
            mds.push(i);
        }

        return ans;
    }

    vector<int> getPGE(vector<int>& heights){
        stack<int> mds;
        int n=heights.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!mds.empty() && heights[mds.top()] < heights[i] ){
                mds.pop();
            }
            if(!mds.empty() && heights[mds.top()] > heights[i] ){
                ans[i]=mds.top();
            }
            mds.push(i);
        }
        return ans;
    }

    vector<int> canSeePersonsCount(vector<int>& heights) {
        //  10   6   8   5   11  9
        //   0   1   2   3   4   5
        //   4   2   4   4   -1  -1 nge        this    
        //   1   3   3   -1   5   -1 nse
        //   -1    0   0   2    -1   4    pge  this
        int n=heights.size();
        vector<int> nge = getNGE(heights);  // can contribute 1
       
        vector<int> pge = getPGE(heights);  // can contribute more than 1
        
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(pge[i]>=0){
                ans[pge[i]]++;
            }
            if(nge[i]>=0){
                ans[i]++;
            }
        }

        return ans;


    }
};
