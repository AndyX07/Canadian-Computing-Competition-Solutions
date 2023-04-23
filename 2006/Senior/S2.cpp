#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, char> mp;
    for(char c = 'A'; c <= 'Z'; c++){
        mp[c]='.';
    }
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);
    string s3;
    getline(cin, s3);
    for(int i = 0; i < s1.size(); i++){
        mp[s2[i]]=s1[i];
    }
    for(char c : s3){
        cout << mp[c];
    }
    cout << endl;
    return 0;
}
