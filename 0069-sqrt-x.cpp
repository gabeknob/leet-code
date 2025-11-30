class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        long int r = (INT_MAX >> 15) - 1;

        long int square;

        while (r >= l) {
            square = l + (r - l) / 2;

            if ((square * square == x) || (square * square <= x && (square + 1) * (square + 1) > x)) {
                return square;
            } else if (square * square > x) {
                r = square - 1;
            } else if (square * square < x) {
                l = square + 1;
            }

        }

        return -1;
    }
};
