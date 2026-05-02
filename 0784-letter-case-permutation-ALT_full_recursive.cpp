class Solution {
public:
    vector<string> res;

    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return res;
    }

    void backtrack(string& s, int start) {
        if (start == s.length()) {
            res.push_back(s);
            return;
        }

        if (isdigit(s[start])) {
            backtrack(s, start + 1);
            return;
        }

        s[start] = tolower(s[start]);
        backtrack(s, start + 1);

        s[start] = toupper(s[start]);
        backtrack(s, start + 1);
    }
};
