#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        queue<int> q;
        q.push(0);
        int first = 0, ans = 0;

        for (int i = 1; i <= tree.size(); i++) {
            if (tree[i] != tree[i-1]) {
                ans = max(ans, i-first);
                q.push(i);
                if (q.size() > 2) {
                    bool ok = false;
                    if (tree[i] != tree[q.front()]) {
                        q.pop();
                        ok = true;
                        first = q.front();
                    }
                    if (!ok) q.pop();
                }
            }
        }
        return ans;

    }
};
int main(int argc, char const *argv[])
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    Solution *s = new Solution();
    cout << s->totalFruit(v) << endl;
    
    return 0;
}
// 1 2 3 2 2