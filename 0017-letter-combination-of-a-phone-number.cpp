class Solution {
public:
    vector<string> res;
    unordered_map<char,vector<char>> letterOptions;

    vector<string> letterCombinations(string digits) {
        letterOptions['2'] = {'a', 'b', 'c'};
        letterOptions['3'] = {'d', 'e', 'f'};
        letterOptions['4'] = {'g', 'h', 'i'};
        letterOptions['5'] = {'j', 'k', 'l'};
        letterOptions['6'] = {'m', 'n', 'o'};
        letterOptions['7'] = {'p', 'q', 'r', 's'};
        letterOptions['8'] = {'t', 'u', 'v'};
        letterOptions['9'] = {'w', 'x', 'y', 'z'};

        string path = digits;
        backtrack(path, digits, 0);

        return res;
    }

    void backtrack(string& path, string& digits, int start) {
        if (start == digits.length()) {
            res.push_back(path);
            return;
        }

        for (char option : letterOptions[digits[start]]) {
            path[start] = option;
            backtrack(path, digits, start + 1);
        }
    }
};
