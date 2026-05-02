class Solution {
public:
    vector<vector<int>> res;

    int finalTarget;
    vector<int> *nums;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        finalTarget = target;

        vector<int> path;
        backtrack(candidates, path, 0, 0);

        return res;
    }

    void backtrack(vector<int>& candidates, vector<int>& path, int start, int sum) {
        if (sum > finalTarget) return;
        if (sum == finalTarget) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            int option = candidates[i];
            int currSum = option + sum;

            if (option > finalTarget) continue;
            if (i > start && option == candidates[i - 1]) continue;

            path.push_back(option);
            backtrack(candidates, path, i + 1, currSum);
            path.pop_back();
        }
    }
};
