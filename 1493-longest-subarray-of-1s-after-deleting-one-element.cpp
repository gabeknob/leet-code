class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lastSeq = 0;
        int currSeq = 0;
        int maxSeq = 0;

        bool noZeroes = false;

        int i = 0;


        while (i < nums.size()) {
            if (nums[i] == 0) {
                lastSeq = 0;
                while (i < nums.size() && nums[i] == 0) i++;
            }

            while (i < nums.size() && nums[i] == 1) {
                currSeq += 1;
                i++;
            }

            maxSeq = max(maxSeq, currSeq + lastSeq);
            lastSeq = currSeq;
            currSeq = 0;
            i++;
        }

        noZeroes = maxSeq == nums.size();


        return maxSeq - noZeroes;
    }
};
