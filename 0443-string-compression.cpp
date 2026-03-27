class Solution {
public:
    int compress(vector<char>& chars) {
        char currChar = chars[0];
        int seq = 0;

        int l = 0;
        int r = 0;

        while (r < chars.size()) {
            while (r < chars.size() && chars[r] == currChar) {
                r++; seq++;
            }
            chars[l] = currChar;
            if (r < chars.size()) currChar = chars[r];

            l += 1;
            if (seq > 1) {
                string sequelSize = to_string(seq);

                int aux = 0;
                while (aux < sequelSize.length()) {
                    chars[l++] = sequelSize[aux++];
                }
            }

            seq = 0;
        }

        return l;
    }
};
