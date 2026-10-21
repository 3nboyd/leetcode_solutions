// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// O(n) time and O(1) auxiliary space for the fixed byte alphabet.
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int left = 0;
        int best = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            left = max(left, lastSeen[c] + 1);
            lastSeen[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
