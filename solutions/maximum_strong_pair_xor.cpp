//https://leetcode.com/problems/maximum-strong-pair-xor-ii/

class Trie{
    vector<Trie*> children;
    int freq;
    bool is_end{};
    public:
    Trie():freq(0),is_end(false),children(2,nullptr){

    };
    void insert(int num){
        Trie* cur = this;
        for(int i=21;i>=0;i--){
            int bit=0;
            if(  num&(1<<i) ) {
                bit=1;
            }
            if(cur->children[bit] == nullptr){
                cur->children[bit] = new Trie();
            }
            cur= cur->children[bit];
            cur->freq++;
        }

    }
    // what is use |x-y| <= min(x,y)
    // 0001  0010 0101                  1000
    int getXor(int num){
        Trie* cur = this;
        int mxXor=0;
        for(int i=21;i>=0;i--){
            int bit=0;
            if(  num&(1<<i) ) {
                bit=1;
            }
            if(cur->children[!bit] != nullptr && cur->children[!bit]->freq > 0){
                mxXor += (1<<i);
                cur= cur->children[!bit];
            }else{
                cur = cur->children[bit];
            }            
        }
        return mxXor;
    }

    void remove(int num){
        Trie* cur = this;
        for(int i=21;i>=0;i--){
            int bit=0;
            if(  num&(1<<i) ) {
                bit=1;
            }
            cur= cur->children[bit];
            cur->freq--;
        }   
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        Trie* trie = new Trie();
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            trie->insert(nums[i]);
            while(j<i && 2*nums[j] < nums[i] ){
                trie->remove(nums[j]);
                j++;
            }
            ans = max(ans, trie->getXor(nums[i]));
        }
        return ans;


    }
};
