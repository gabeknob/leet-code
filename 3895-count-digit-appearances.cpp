class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        string num = to_string(digit);
        char n = num[0];
        
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);

            for (char c : s) {
                if (c == n) count++;
            }
        }

        return count;
    }
};
