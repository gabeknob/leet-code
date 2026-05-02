class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> occurences {};

        int maxWindow = 1;

        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char currChar = s[right];

            if (!occurences.count(currChar)) {
                occurences.insert(currChar);
            } else {
                while (s[left] != currChar) occurences.erase(s[left++]);
                occurences.insert(++left);
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return maxWindow;
    }
}; 
