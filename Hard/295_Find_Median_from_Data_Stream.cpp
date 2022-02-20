//https://leetcode.com/problems/find-median-from-data-stream/

/*
  I used here the max heap and min heap technique.
*/

class MedianFinder {

public:
     priority_queue<int> maxHeap;
     priority_queue<int,vector<int>,greater<int>> minHeap;
    
    
    /** initialize your data structure here. */
    MedianFinder() {
        this->maxHeap = maxHeap;
        this->minHeap = minHeap;
    }
    
    void addNum(int num) {
        if(maxHeap.empty()||maxHeap.top()>num) maxHeap.push(num);
        else minHeap.push(num);
        
        if(maxHeap.size()>1+minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>1+maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return ((double)maxHeap.top()+(double)minHeap.top())/2;
        }
        else if(minHeap.size()>maxHeap.size()){
            return (double)minHeap.top();
        }
        else{
            return (double)maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */