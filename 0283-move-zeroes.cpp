class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;

        for (int r = 1; r < nums.size(); r++) {
            while (l < r && nums[l] != 0) {
                l++;
            }

            if (nums[l] == 0 && nums[r] != 0) {
                int aux = nums[l];
                nums[l] = nums[r];
                nums[r] = aux;
                l++;
            }
        }
    }
};
