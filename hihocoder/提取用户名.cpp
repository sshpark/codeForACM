#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
    char str[805], r[805];
    cin.getline(str, 1005);
    int len = strlen(str), j;
    for (int i = 0; i < len; i++) {
        if (str[i] == '@') {
            j = i+1;
            while (j < len && isalpha(str[j])) printf("%c", str[j++]);
            if (j > i+1) printf(" ");
            i = j-1;
        }
    }
    printf("\n");
    return 0;
}