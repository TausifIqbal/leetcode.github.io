// https://leetcode.com/problems/sliding-window-median/description/
struct kMedian {
    int k{};
    multiset<double> left; //smaller;
    multiset<double> right;  // greater ele
    kMedian(int _k):k(_k){};
    void push(int ele){
    
        if(right.empty() || *right.begin() < ele ){
            right.insert(ele);
        }else{
            left.insert(ele);
        }
        adjustSize();
    }
   
    double getMedian(){
        int mxsz = left.size();
        int mnsz = right.size();
        if(k%2==0){
            return  ( *left.rbegin()+  *right.begin())/2;
        } 
        return *right.begin();
    }
    void remove(int ele){
        auto itr = left.find(ele);
        if(itr!=left.end()){
            left.erase(itr);
        }else{
            itr = right.find(ele);
            right.erase(itr);
            
        }
        adjustSize();
    }
    void adjustSize(){
        if(int(left.size())- int(right.size()) >=1 ){
                auto itr = std::prev(left.end());
                int ele = *itr;
                left.erase(itr);
                right.insert(ele);
        }else if(int(right.size())-int(left.size())>1 ){
                auto itr = right.cbegin();
                int ele  = *itr;
                right.erase(itr);
                left.insert(ele);
        } 
    }
};

class Solution {
public:

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n=nums.size();
        kMedian k_median(k);
        for(int i=0;i<n;i++){
            k_median.push(nums[i]);
            if(i>=k-1){
                ans.push_back(k_median.getMedian());
                k_median.remove(nums[i-k+1]);
            }
        }
        return ans;

        
    }
};
