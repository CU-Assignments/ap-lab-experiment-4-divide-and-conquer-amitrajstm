#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) return "";

        unordered_set<char> charSet(s.begin(), s.end());

        for (int i = 0; i < s.length(); ++i) {
            if (charSet.count(tolower(s[i])) == 0 || charSet.count(toupper(s[i])) == 0) {
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));
                return left.length() >= right.length() ? left : right;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "YazaAay";
    cout << "Longest Nice Substring: " << sol.longestNiceSubstring(s) << endl;
    return 0;
}
