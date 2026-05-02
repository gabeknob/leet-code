class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int validArrs = 0;

        int left = 0;
        int currProd = 1;
        if (k <= 1) return 0;
        for (int right = 0; right < nums.size(); right++) {
            currProd *= nums[right];
            while (currProd >= k) currProd /= nums[left++];
            validArrs += right - left + 1;
        }

        return validArrs;
    }
};
