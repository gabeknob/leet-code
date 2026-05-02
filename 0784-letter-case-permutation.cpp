class Solution {
public:
    vector<string> res;
    int stringLen;

    vector<string> letterCasePermutation(string s) {
        stringLen = s.length();

        vector<vector<char>> options;
        for (int i = 0; i < stringLen; i++) {
            options.push_back(generateOptions(s[i]));
        }

        // for (int i = 0; i < options.size(); i++) {
        //     for (int j = 0; j < options[i].size(); j++) {
        //         cout << options[i][j] << ' ';
        //     }
        // }
        // cout << '
';

        string path = ;
        backtrack(path, options, 0);

        return res;
    }

    void backtrack(string& path, vector<vector<char>>& options, int start) {
        if (path.length() == stringLen) {
            res.push_back(path);
            return;
        }

        // for (char c : path) cout << c << ' ';
        // cout << '
';

        for (int i = 0; i < options[start].size(); i++) {
            char option = options[start][i];

            path.push_back(option);
            backtrack(path, options, start + 1);
            path.pop_back();
        }
    }

    vector<char> generateOptions(char c) {
        vector<char> options;
        options.push_back(c);

        if (c >= 'a' && c <= 'z') options.push_back(c + ('A' - 'a'));
        if (c >= 'A' && c <= 'Z') options.push_back(c - ('A' - 'a'));

        return options;
    }
};
