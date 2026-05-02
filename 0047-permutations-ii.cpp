class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<int> path;

        backtrack(nums, path, used);

        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        unordered_set<int> usedValues;

        for (int i = 0; i < used.size(); i++) {
            if (used[i]) continue;
            if (usedValues.count(nums[i])) continue;

            path.push_back(nums[i]);
            used[i] = true; 

            usedValues.insert(nums[i]);
            backtrack(nums, path, used);

            path.pop_back();
            used[i] = false;

            
        }
    }
};
