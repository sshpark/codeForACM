#include <stdio.h>  
#include <iostream>  
#include <vector>  
#include <string>  
#include <algorithm>  
using namespace std;   
int string_split(string str,vector<string> &vstr)  
{
    string tmp;  
    int n=-1;  
      
    while(str.find(" ")!=string::npos){  
        n = str.find(" ");  
        tmp = str.substr(0,n);  
        vstr.push_back(tmp);  
        str=str.substr(n+1,str.size());  
    }  
    vstr.push_back(str);  
    return vstr.size();  
}  
  
int main(int argc, char const *argv[])  
{   
    string keystr;  
    getline(cin,keystr);  
    vector<string> keyvstr;  
    string_split(keystr,keyvstr);  
    string str;  
    getline(cin,str);  
    vector<string> vstr;  
      
    string_split(str,vstr);  
    for (int i = 0; i < keyvstr.size(); ++i)  
    {  
        string s = keyvstr[i];  
            sort(s.begin(),s.end());
        for (int j = 0; j < vstr.size(); ++j)  
        {  
            string ss = vstr[j];  
            sort(ss.begin(),ss.end());
            if (ss.compare(s)==0)
            {  
                cout<<keyvstr[i]<<" ";  
            }  
        }  
    }  
      
    return 0;  
}