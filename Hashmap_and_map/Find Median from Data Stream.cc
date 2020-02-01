/*
class MedianFinder {
public:
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if (count % 2 == 0) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        
        if (!min_heap.empty() && min_heap.top() < max_heap.top()) {
            int temp = min_heap.top();
            min_heap.pop();
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(temp);
        }
        
        count++;
    }
    
    double findMedian() {
        if (count % 2 == 1) {
            return max_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
    
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int count;
};
*/
    
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
public:
    MedianFinder() {
        count = 0;  
    }
    
    void addNum(int num) {
        A.insert(num);
        
        if (count == 0) {
            median = A.begin();
            count++;
            return;
        }
        
        if (count % 2 == 0) {
            if (num >= *median) {
                ++median;
            }
        } else {
            if (num < *median) {
                --median;
            }
        }
        count++;
    }
    
    double findMedian() {
        if (count % 2 == 0) {
            multiset<int>::iterator temp = median;
            ++temp;
            return (*median + *temp) / 2.0;
        } else {
            return *median;
        }
    }
    
private:
    multiset<int> A;
    multiset<int>::iterator median;
    int count;
};
