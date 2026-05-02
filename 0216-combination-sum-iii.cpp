class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtrack(path, 0, k, n, 1);

        return res;
    }

    void backtrack (vector<int>& path, int sum, int& k, int& n, int start) {
        if (path.size() > k || sum > n) return;

        if (path.size() == k && sum == n) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < 10; i++) {
            int option = i;
            int currSum = sum + option;

            path.push_back(option);
            backtrack(path, currSum, k, n, i + 1);
            path.pop_back();
        }
    }
};
