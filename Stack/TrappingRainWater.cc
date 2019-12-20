class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        
        int left = 0, right = height.size() - 1;
        int left_height = height[left], right_height = height[right];
        
        int res = 0;
        while (left < right) {
            while (left < right && left_height <= right_height) {
                left++;
                if (height[left] < left_height) {
                   res += left_height - height[left]; 
                } else {
                    left_height = height[left];
                }
            }
            
            while (left < right && left_height > right_height) {
                right--;
                if (height[right] < right_height) {
                   res += right_height - height[right]; 
                } else {
                    right_height = height[right];
                }
            }
        }
        
        return res;
    }
};
