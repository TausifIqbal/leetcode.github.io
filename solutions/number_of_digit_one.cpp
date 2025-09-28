// https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
    map<array<int,3>,int> digitDp;
    //  for each digit iterate from right to left
    //  cur_count : count of 1 seen so far from right to left
    int solve(int id, bool tight, string num,int cur_count){
        int n=num.size();
        if(id>=n){
            return cur_count;
        }
        if(digitDp.count({id,cur_count,tight})){
            return digitDp[{id,cur_count,tight}];
        }
        int limit = tight  ? num[id]-'0' : 9;
        int count=0;
        for(int digit=0;digit<=limit;digit++){
            bool newtight = tight ? (digit ==limit): tight;
            if(digit==1){
                count += solve(id+1,newtight,num,cur_count+1);
            }else{
                count += solve(id+1,newtight,num,cur_count);
            }
            
        }
        return digitDp[{id,cur_count,tight}]=count;

    }
    int countDigitOne(int n) {
        string num = to_string(n);
        int ans = solve(0,true,num,0); 
        return ans;
    }
};
