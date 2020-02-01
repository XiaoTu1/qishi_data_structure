class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) {
            return vector<double>();
        }
        
        multiset<long> max, min;
        
        for (int i = 0; i < k; i++) {
            max.insert(nums[i]);
        }
        
        for (int i = 0; i < k / 2; i++) {
            min.insert(*max.rbegin());
            max.erase(--max.end());
        }
        
        vector<double> res;
        res.push_back(*max.rbegin());
        if (k % 2 == 0) {
            res.back() = (*max.rbegin() + *min.begin()) / 2.0;
        }
        
        for (int i = k; i < nums.size(); i++) {
            if (max.find(nums[i - k]) != max.end()) {
                max.erase(max.find(nums[i - k]));
                max.insert(nums[i]);
            } else {
                min.erase(min.find(nums[i - k]));
                min.insert(nums[i]);
            }
            
            if (!min.empty() && *max.rbegin() > *min.begin()) {
                int temp = *min.begin();
                min.erase(min.begin());
                min.insert(*max.rbegin());
                max.erase(--max.end());
                max.insert(temp);
            }
            
            res.push_back(*max.rbegin());
            if (k % 2 == 0) {
                res.back() = (*max.rbegin() + *min.begin()) / 2.0;
            }
        }
        
        return res;
    }
};
