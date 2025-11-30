class Solution {
public:
    string reverseVowels(string s) {
        int l = 0; int r = s.size() - 1;
        set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (l < r) {
            while (l < r && !vowels.count(s[l])) {
                l++;
            }
            while (l < r && !vowels.count(s[r])) {
                r--;
            }

            if (vowels.count(s[l]) && vowels.count(s[r])) {
                char aux = s[l];
                s[l] = s[r];
                s[r] = aux;
                l++; r--;
            }
        }

        return s;
    }
};
