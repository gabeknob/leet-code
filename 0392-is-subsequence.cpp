class Solution {
public:
    bool isSubsequence(string s, string t) {
        int c1 = 0; int c2 = 0;

        while (c1 < s.length()) {
            while (t[c2] != s[c1]) {
                if (c2 >= t.length()) return false;
                c2++;
            }
            c1++;
            c2++;
        }

        return c1 == s.length();
    }
};
