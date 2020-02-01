class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // write your code here
        bool ans;
        if (hash.find(val) == hash.end()) {
            ans = true;
        } else {
            ans = false;
        }
        
        int count = hash[val].size();
        nums.push_back({val, count});
        size++;
        hash[val].push_back(size - 1);
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // write your code here
        if (hash.find(val) == hash.end()) {
            return false;
        }
        
        int index = hash[val].back();
        nums[index] = nums.back();
        nums.pop_back();
        size--;
        hash[val].pop_back();
        if (hash[val].empty()) {
            hash.erase(val);
        }
        if (index != size) {
            hash[nums[index].first][nums[index].second] = index;    
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // write your code here
        int r = rand() % size;
        return nums[r].first;
    }
    
private:
    unordered_map<int, vector<int>> hash;
    vector<pair<int, int>> nums;
    int size = 0;
};
