class Solution {
public:
    bool isValid(string s) {
        stack<char> openers;

        for (char c : s) {
            switch(c) {
                case '{':
                case '[':
                case '(':
                    openers.push(c);
                    break;
                case '}':
                    if (openers.empty()) return false;
                    if (openers.top() != '{') return false;
                    openers.pop();
                    break;
                case ']':
                    if (openers.empty()) return false;
                    if (openers.top() != '[') return false;
                    openers.pop();
                    break;
                case ')':
                    if (openers.empty()) return false;
                    if (openers.top() != '(') return false;
                    openers.pop();
                    break;
                default:
                    break;
            }
        }

        return openers.empty();
    }
};
