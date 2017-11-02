#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    int c = 0;
    cin >> s;
    if (s.find("Danil") < 100) c++;
    if (s.find("Olya") < 100) c++;
    if (s.find("Slava") < 100) c++;
    if (s.find("Ann") < 100) c++;
    if (s.find("Nikita") < 100) c++;
    if (c == 1) puts("Y");
    else puts("NO");
    return 0;
}