class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> path;
        backtrack(nums, path, 0);

        return res;
    }

    void backtrack (vector<int>& nums, vector<int>& path, int start) {
        res.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            int option = nums[i];

            if (i > start && option == nums[i - 1]) continue;

            path.push_back(option);
            backtrack(nums, path, i + 1);
            path.pop_back();
        }
    }
};
