class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        int c1 = 0;
        int maxsize = 1;
        map<char, int> pool { { s[0], 0 } };

        for (int c2 = 1; c2 < s.size(); c2++) {
            if (pool.count(s[c2])) {
                int nstart = pool[s[c2]] + 1;
                while (c1 < nstart) {
                    pool.erase(s[c1]);
                    c1++;
                }

                pool[s[c2]] = c2;
            } else {
                pool.insert({ s[c2], c2 });
                maxsize = max(maxsize, c2 - c1 + 1);
            }
        }

        return maxsize;
    }
};
