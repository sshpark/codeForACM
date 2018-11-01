// 给定一个字符串，找出不含有重复字符的最长子串的长度。
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, ans = 0;
        int n = static_cast<int>(s.size());
        set<char> p;
        i = j = 0;

        while (i < n && j < n) {
            if (p.find(s[j]) == p.end()) {
                p.insert(s[j]);
                j++;
                ans = max(ans, j-i);
            } else {
                p.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    string x = "abcabcbb";
    cout << s->lengthOfLongestSubstring(x) << endl;
    return 0;
}