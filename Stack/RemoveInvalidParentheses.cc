class Solution {
public:
    int left = 0;
    int right = 0;
    
    vector<string> removeInvalidParentheses(string s) {
        stack<string> S;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            }
            if (s[i] == '(') {
                S.push(string(1, s[i]));
            } else {
                if (!S.empty() && S.top() == "(") {
                    S.pop();
                } else {
                    S.push(string(1, s[i]));
                }
            }
        }
        
        while (!S.empty()) {
            if (S.top() == "(") {
                left++;
                S.pop();
            } else {
                right++;
                S.pop();
            }
        }
    
        vector<string> results;
        dfs(results, s, 0);
        
        return results;
    }
    
    void dfs(vector<string>& results, string& s, int pos) {
        if (left == 0 && right == 0) {
            if (valid(s)) {
                results.push_back(s);
                return;
            } else {
                return;
            }
        }
        
        for (int i = pos; i < s.size(); i++) {
            if (s[i] != ')' && s[i] != '(') {
                continue;
            }
            if (i > pos && s[i] == s[i - 1]) {
                continue;
            }
            if (right > 0 && s[i] == ')') {
                s = s.substr(0, i) + s.substr(i + 1, s.size());
                right--;
                dfs(results, s, i);
                right++;
                s = s.substr(0, i) + ')' + s.substr(i, s.size());
            } else if (right == 0 && left > 0 && s[i] == '(') {
                s = s.substr(0, i) + s.substr(i + 1, s.size());
                left--;
                dfs(results, s, i);
                left++;
                s = s.substr(0, i) + '(' + s.substr(i, s.size());  
            }
        }
    }
    
    bool valid(string& s) {
        stack<string> S;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            }
            if (s[i] == '(') {
                S.push(string(1, s[i]));
            } else {
                if (!S.empty() && S.top() == "(") {
                    S.pop();
                } else {
                    return false;
                }
            }
        }
        
        return S.empty();
    }
};
