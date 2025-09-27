// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
    
    priority_queue<int> mxpq; // max_heap;
    priority_queue<int,vector<int>,greater<int>> mnpq;  // greater ele

public:
    MedianFinder() {
    }
    
    void addNum(int ele) {
        if(mnpq.empty()  || mnpq.top()<= ele ){
            mnpq.push(ele);
        }else{
            mxpq.push(ele);
        }
        adjustSize();
    }
    
    double findMedian() {
        int mxsz = mxpq.size();
        int mnsz = mnpq.size();
        if(mxsz==0 && mnsz==0){
            return 0.0;
        }
        if(mxsz == mnsz){
            return ((mxpq.top() + mnpq.top())*1.0)/2;
        } 
        if(mxsz>mnsz){
            return mxpq.top();
        }
        return mnpq.top();
    }

    void adjustSize(){
        // 0 unsigned - 1 unsigned give positive number so use type cast
        if( int(mxpq.size() - mnpq.size())  >= 1){
                int ele = mxpq.top();
                mxpq.pop();
                mnpq.push(ele);
        }else if( int(mnpq.size() -mxpq.size()) > 1){
                int ele = mnpq.top();
                mnpq.pop();
                mxpq.push(ele);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
