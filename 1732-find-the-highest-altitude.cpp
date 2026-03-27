class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev = 0;
        int largest = 0;

        for (int i = 0; i < gain.size(); i++) {
            largest = max(largest, prev + gain[i]);
            prev = gain[i] + prev;
        }

        return largest;
    }
};
