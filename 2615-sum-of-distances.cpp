class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> arr(nums.size(), 0);
        unordered_map<long long, vector<long long>> occurences {};

        for (int i = 0; i < nums.size(); i++) {
            occurences[nums[i]].push_back(i);
        }

        for (auto& [key, pos] : occurences) {
            long long totalSum = 0;
            for (int p : pos) totalSum += p;

            long long leftSum = 0;
            int m = pos.size();

            for (int i = 0; i < m; i++) {
                long long target = pos[i];
                long long rightSum = totalSum - leftSum - target;

                long long leftCount = i;
                long long rightCount = m - 1 - i;

                long long currentDist = (leftCount * target - leftSum) + (rightSum - rightCount * target);

                arr[target] = currentDist;

                leftSum += target;
            }
        }

        return arr;
    }
};
