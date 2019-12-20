class Solution {
public:
    string decodeString(string &s) {
        stack<int> intS;
        stack<string> stringS;
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int j = i;
                while (s[j] != '[') {
                    j++;
                }
                int tempN = atoi(s.substr(i, j).c_str());
                intS.push(tempN);
                i = j - 1;
            } else if (s[i] == '[') {
                stringS.push(string(1, s[i]));
            } else if (s[i] == ']') {
                string tempS;
                while (stringS.top() != "[") {
                    string top = stringS.top();
                    stringS.pop();
                    tempS = top + tempS;
                }
                stringS.pop();
                int tempN = intS.top();
                intS.pop();
                for (int i = 0; i < tempN; i++) {
                    stringS.push(tempS);
                }
            } else {
                stringS.push(string(1, s[i]));
            }
        }
        
        string res;
        while (!stringS.empty()) {
            string top = stringS.top();
            stringS.pop();
            res = top + res;
        }
        
        return res;
        
    }
};
