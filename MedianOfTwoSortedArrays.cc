class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if ((m + n) % 2 == 1) {
            return findKthNumber((m + n) / 2 + 1, nums1, nums2, 0, 0);
        } else {
            return (findKthNumber((m + n) / 2, nums1, nums2, 0, 0) + findKthNumber((m + n) / 2 + 1, nums1, nums2, 0, 0)) / 2.0;
        }
    }
    
    int findKthNumber(int k, vector<int>& A, vector<int>& B, int A_start, int B_start) {
        if (A_start == A.size()) {
            return B[B_start + k - 1];
        }
        if (B_start == B.size()) {
            return A[A_start + k - 1];
        }
        if (k == 1) {
            return min(A[A_start], B[B_start]);
        }
        
        int A_ele, B_ele;
        A_ele = (A_start + k / 2 - 1 < A.size()) ? A[A_start + k / 2 - 1] : INT_MAX;
        B_ele = (B_start + k / 2 - 1 < B.size()) ? B[B_start + k / 2 - 1] : INT_MAX;
        
        if (A_ele < B_ele) {
            return findKthNumber(k - k / 2, A, B, A_start + k / 2, B_start);
        } else {
            return findKthNumber(k - k / 2, A, B, A_start, B_start + k / 2);   
        }
    }
};
