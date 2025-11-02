// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

class Solution {
public:
    string num;
    map<array<int,2>,int> mp;
    int solve(int id, bool tight, vector<string>& digits){
        // num = 421
        int n = num.size();
        if(id >= n){
            // we constructed one number return that number
            return 1;
        }
        if( mp.count({id,tight}) ){
            return mp[{id,tight}];
        }
        int tmp=0;
        int digit =  num[id]-'0';
        int limit = tight? digit:9;

        for(auto ds:digits){
            int d = stoi(ds);
            if(d < limit){
                tmp += solve(id+1,false,digits);
            }else if(d == limit){
                tmp += solve(id+1,tight,digits);
            }
        }

        return mp[{id, tight}] = tmp;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        int ans=0;
        num = to_string(n);
        int prod = 1;
        int k = digits.size();
        for(int i=1;i<num.size();i++){
            prod *= k;
            ans += prod;
        }
        ans += solve(0,true,digits);
        return ans;
    }
};
