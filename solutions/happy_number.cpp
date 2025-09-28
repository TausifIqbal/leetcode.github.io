https://leetcode.com/problems/happy-number/
class Solution {

    int getSq(int n){
        int sum=0;
        string num = to_string(n);
        for(char d: num){
            sum += (d-'0')*(d-'0');
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        // simulate?
        int slow=n;
        int fast=n;
        while(true){
            slow = getSq(slow);
            fast = getSq(getSq(fast));
            if(slow == 1){
                return true;
            }
            if(slow ==fast){
                return false;
            }
        }
        return false;
    }
};

