//https://leetcode.com/problems/heaters/

class Solution {
public:
    bool valid(vector<int>& houses, vector<int>&heaters,int r){
        int i=0,j=0;
        int n=houses.size();
        int m=heaters.size();
        while(i<n && j<m){
            if(abs(houses[i]-heaters[j])  <=r){
                i++;
            }else{
                j++;
            }
        }
        return i==n;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l=0, r =1e9+7; // change it
        int ans=0;
        while(l<=r){
            int m = (r-l)/2 +l;
            if(valid(houses,heaters,m)){
                ans = m;
                r =m -1;
            }else{
                l =m+1;
            }
        }
        return ans;
    }
};
