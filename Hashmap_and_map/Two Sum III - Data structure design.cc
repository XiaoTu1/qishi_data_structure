class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        hash[number]++;
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        for (auto e: hash) {
            if (e.first == 0.5 * value && e.second > 1) {
                return true;
            }
            if (e.first != 0.5 * value && hash.find(value - e.first) != hash.end()) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    unordered_map<int, int> hash;
    
};
