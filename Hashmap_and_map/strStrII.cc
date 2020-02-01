class Solution {
public:
    int BASE = 1000000;
    
    int strStr2(const char* source, const char* target) {
        // write your code here
        if (source == NULL || target == NULL) {
            return -1;
        }
        
        if (target[0] == 0) {
            return 0;
        }
        
        int length = 0;
        int power = 1;
        int targetCode = 0;
        for (int i = 0; target[i] != 0; i++) {
            power = power * 31 % BASE;
            length++;
            targetCode = (targetCode * 31 + target[i]) % BASE;
        }
        
        int sourceCode = 0;
        for (int i = 0; source[i] != 0; i++) {
            sourceCode = (sourceCode * 31 + source[i]) % BASE;
            
            if (i < length - 1) {
                continue;
            }
            
            if (i >= length) {
                sourceCode = (sourceCode - source[i - length] * power) % BASE;
                if (sourceCode < 0) {
                    sourceCode = sourceCode + BASE;
                }
            }
            
            if (sourceCode == targetCode) {
                int j;
                for (j = 0; target[j] != 0; j++) {
                    if (source[i - length + j + 1] != target [j]) {
                        break;
                    }
                }
                if (target[j] == 0) {
                    return i - length + 1;
                }
            }
        }
        
        return -1;
    }
};
