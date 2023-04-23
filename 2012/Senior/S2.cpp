#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int t=0;
    string v="IVXLCDM";
    int prev=0;
    char c='I';
    for(int i=0;i<s.size();i+=2){
        int temp;
        if(s[i+1]=='I')temp=(s[i]-'0')*1;
        if(s[i+1]=='V')temp=(s[i]-'0')*5;
        if(s[i+1]=='X')temp=(s[i]-'0')*10;
        if(s[i+1]=='L')temp=(s[i]-'0')*50;
        if(s[i+1]=='C')temp=(s[i]-'0')*100;
        if(s[i+1]=='D')temp=(s[i]-'0')*500;
        if(s[i+1]=='M')temp=(s[i]-'0')*1000;
        t+=temp;
        if(v.find(c)<v.find(s[i+1]))t-=prev*2;
        prev=temp;
        c=s[i+1];
    }
    cout << t << endl;
    return 0;
}
