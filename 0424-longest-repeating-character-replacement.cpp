class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq {};

        int maxWindow = 0;
        int maxFreq = 0;

        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            int currWindow = right - left + 1;

            while (currWindow - maxFreq > k) {
                freq[s[left]]--;
                left++;
                currWindow--;
            }

            maxWindow = max(maxWindow, currWindow);
        }

        return maxWindow;
    }
};
