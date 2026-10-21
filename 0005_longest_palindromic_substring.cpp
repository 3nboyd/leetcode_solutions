// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
// O(n^2) time and O(1) auxiliary space, excluding the returned string.
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = static_cast<int>(s.size());
        int bestStart = 0, bestLength = 0;
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            int length = right - left - 1;
            if (length > bestLength) {
                bestStart = left + 1;
                bestLength = length;
            }
        };
        for (int center = 0; center < n; ++center) {
            expand(center, center);
            expand(center, center + 1);
        }
        return s.substr(bestStart, bestLength);
    }
};