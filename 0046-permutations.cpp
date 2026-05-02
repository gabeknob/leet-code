class Solution {
public:
    vector<vector<int>> perms;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        vector<int> path;
        vector<bool> used(n, false);
        backtrack(path, nums, used);

        return perms;
    }

    void backtrack(vector<int>& path, vector<int>& options, vector<bool>& used) {
        if (path.size() == n) perms.push_back(path);

        for (int i = 0; i < options.size(); i++) {
            if (used[i]) continue;

            path.push_back(options[i]);
            used[i] = true;
            backtrack(path, options, used);
            path.pop_back();
            used[i] = false;
        }
    }
};
