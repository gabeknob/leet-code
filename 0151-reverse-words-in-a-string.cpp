class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;

        while(i < n){
            while(i < n && s[i] == ' ') i++; // look for first valid char
            if (i == n) break; // out of bounds prevention

            while(i < n && s[i] != ' '){ // copy from i to right, who was left behind
                s[right] = s[i];
                right++; i++;
            }

            reverse(s.begin() + left, s.begin() + right);

            s[right++] = ' '; // overwrites a space after finished word
            left = right;
            i++; // look for the next word
        }

        s.resize(right - 1); // crop rest
        return s;
    }
};
