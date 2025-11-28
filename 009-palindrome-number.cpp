class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        string pal = to_string(x);

        int i = 0;
        int j = pal.length() - 1;

        while (i < j) {
            if (pal[i] != pal[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
