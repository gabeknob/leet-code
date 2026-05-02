class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        span<int> slice{nums};

        for (int i = 0; i <= nums.size() - k; i++) {
            bool isValid = isOrdered(slice.subspan(i, k));
            if (isValid) res.push_back(slice.subspan(i, k)[k - 1]);
            else res.push_back(-1);
        }

        return res;
    }

    bool isOrdered(span<int> nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) return false;
        }

        return true;
    }
};
