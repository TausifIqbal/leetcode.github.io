// https://leetcode.com/problems/number-of-digit-one/
class Solution {
public:
    string num;
    map<array<int,3>,int> mp;
    int solve(int id, bool tight,int count){
        int n=num.size();
        if(n<=id){
            // we have constructed one such number with total # of `1` = count
            return count ;
        }
        if(mp.count({id, tight, count})){
            return mp[{id,tight,count}];

        }
        int total =0;
        int limit = tight ? num[id]-'0':9;
        for(int d=0;d<=limit;d++){
            bool ntight = d==limit?tight :0;
            int ncount = d==1? count+1:count;
            total +=  solve(id+1,ntight ,ncount);
        }
        mp[{id,tight,count}]=total;
        return total;
    }
    int countDigitOne(int n) {
        num = to_string(n);
        return solve(0,true,0);
    }
};
