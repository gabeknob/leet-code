class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(path, 0, target, 0, candidates);

        return res;
    }

    void backtrack(vector<int>& path, int sum, int target, int start, vector<int>& candidates) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            int option = candidates[i];
            int currSum = sum + option;

            path.push_back(option);
            backtrack(path, currSum, target, i, candidates);
            path.pop_back();
        }
    }
};
