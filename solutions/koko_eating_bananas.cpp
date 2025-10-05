//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
    bool valid(int k, vector<int>& piles, long long h){
        long long time = 0;
        for_each(piles.begin(),piles.end(),[&k,&time](int a){
            time += a/k + (a%k != 0);
        });
        
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        int ans=l;
        while(l<=r){
            int m = (r+l)/2;
            if(valid(m,piles,h)){
                ans = m;
                r=m-1;
            }else{
                l=m+1;
            }
        }

        return ans;
    }
};
