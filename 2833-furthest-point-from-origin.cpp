class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lefts = 0;
        int rights = 0;
        int credits = 0;

        for (auto c : moves) {
            if (c == 'L') lefts++;
            if (c == 'R') rights++;
            if (c == '_') credits++;
        }

        return abs(lefts - rights) + credits;
    }
};
