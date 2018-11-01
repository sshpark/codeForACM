#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
class Solution {
public:
    int mod = 1000000007;
    int sumSubarrayMins(vector<int>& A) {
        int sum = 0;
        vector<int> B(A.size()+10);
        B[0] = A[0];
        for (int i = 1; i < A.size(); i++)
            B[i] = A[i]+B[i-1];
        for (int i = 0; i < A.size(); i++)
            sum = (sum%mod+B[i]%mod)%mod;
        int n = A.size();
        sum = (sum%mod*n)%mod;
        int cnt = n;
        for (int i = 0; i < n; i++) {
            sum = (sum-A[i]*cnt+mod)%mod;
            cnt--;
        }
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}