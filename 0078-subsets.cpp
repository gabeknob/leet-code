class Solution {
public:
    vector<vector<int>> allSets;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> path;

        backtrack(path, nums, 0);

        return allSets;
    }

    void backtrack(vector<int>& path, vector<int>& options, int start) {
        allSets.push_back(path);

        for (int i = start; i < options.size(); i++) {
            path.push_back(options[i]);
            backtrack(path, options, i + 1);
            path.pop_back();
        }
    }
};
