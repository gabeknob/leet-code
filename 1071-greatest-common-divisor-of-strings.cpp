class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int sizeLimit = gcd(str1.length(), str2.length());

        if (str1 + str2 != str2 + str1) return ;
        return str1.substr(0, sizeLimit);
    }
};
