class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        int i = k - 1;

        while (i > 0) {
            pq.pop();

            i--;
        }

        return pq.top();
    }
};
