class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());

        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = nums[i] * prod;
            prod = answer[i];
        }

        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            answer[i] = i > 0 ? answer[i - 1] * prod : prod;
            prod *= nums[i];
        }

        return answer;
    }
};
