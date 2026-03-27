class Solution {
public:
    int maxVowels(string s, int k) {
        int currVowels = 0;
        int maxVowels = 0;
        set<char> vowels {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < s.length(); i++) {
            if (vowels.count(s[i])) currVowels++;

            if (i >= k - 1) {
                if ((i - k) >= 0 && vowels.count(s[i - k])) currVowels--;
                maxVowels = max(maxVowels, currVowels);
            }
        }

        return maxVowels;
    }
};
