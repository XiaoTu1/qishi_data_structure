class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() < 3) {
            return results;
        }
        
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1, right = len - 1;
            while (left < right) {
                while (left < right && (nums[i] + nums[left] + nums[right] < 0 || (left > i + 1 && nums[left] == nums[left - 1]))) {
                    left++;
                }
                while (left < right && (nums[i] + nums[left] + nums[right] > 0 || (right < len - 1 && nums[right] == nums[right + 1]))) {
                    right--;
                }
                if (left < right && nums[i] + nums[left] + nums[right] == 0) {
                    vector<int> result;
                    result.push_back(nums[i]);
                    result.push_back(nums[left]);
                    result.push_back(nums[right]);
                    results.push_back(result);
                    left++;
                    right--;
                }
            }
        }
        
        return results;
    }
};
