//https://leetcode.com/problems/count-special-integers

class Solution {
public:
    string num;
    map<array<int,3>,int> mp;
    int solve(int id,bool tight,int mask){
        int n=num.size();
        if(id==n){
            return mask!=0;
        }
        if(mp.count({id,tight,mask})){
            return mp[{id,tight,mask}];
        }

        int limit = tight? num[id]-'0' : 9;
        int total=0;
        for(int d=0;d<=limit;d++){
            bool newTight = tight && (d == limit);
            // leading zeros
            if(mask==0 && d==0 ){
                total += solve(id+1,newTight,0);
            }else if(! (mask & (1<<d) )){
            // if I use d ,
            //  I am not allowd to use d again to construct the number
                total += solve(id+1, newTight, mask | (1<<d));
            }
        }
        mp[{id,tight,mask}]=total;
        return total;
    }

    int countSpecialNumbers(int n) {
        num = to_string(n);
        vector<bool> vis(10,false);
        return solve(0,true,0);
    }
};
