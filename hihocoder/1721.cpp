#include <iostream>  
#include <cstring>  
#include <cmath>  
#include <string>  
#include <sstream>  
#include <algorithm>  
#include <queue>  
#include <deque>  
#include <stack>  
#include <set> 
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
//#include<bits/stdc++.h>


bool isPalindrome(string s)
{
    for (int i = 0,  j = s.size() - 1; i < j; ++i, --j)
    {
        if (s[i] != s[j]) return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    int len = s.size(), mid = len / 2;
    bool flag = true;
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
    {
        if (s[i] != s[j]){
            if (isPalindrome(s.substr(i+1, j - i)))
            {
                while (i > 0 && s[i] == s[i - 1]) --i;
                cout << i + 1 << endl;
            }
            else cout << j + 1 << endl;
            //else if (isPalindrome(s.substr(i, j - i)))
            //{
            //  cout << j+1 << endl;
            //  //while (i > 0 && s[i] == s[i - 1]) --i;
            //}
            flag = false;
            break;

        }
    }
    if (flag){ 
        //cout << len / 2 << endl; 
        int i = len / 2; 
        while (i > 0 && s[i] == s[i - 1]) --i;
        cout << i+1 << endl;
    }
    return 0;
}

// abcddczba