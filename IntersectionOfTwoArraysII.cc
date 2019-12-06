class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0) {
            return vector<int>();
        }
        
        unordered_map<int, int> hash;
        for (int i = 0; i < nums1.size(); i++) {
            hash[nums1[i]]++;
        }
        
        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (hash.find(nums2[i]) != hash.end()) {
                hash[nums2[i]]--;
                if (hash[nums2[i]] == 0) {
                    hash.erase(nums2[i]);
                }
                result.push_back(nums2[i]);
            }
        }
        
        return result;
    }
};
