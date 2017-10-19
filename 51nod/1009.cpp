#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;
int main(int argc, char const *argv[])
{
    bitset<32> bit;
    int n;
    cin >> n;
    bit = n;
    cout << bit.count() << endl;
    return 0;
}