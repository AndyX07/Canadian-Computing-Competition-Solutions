#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c[26];
    memset(c, 0, sizeof(c));
    string s;
    cin >> s;
    string s1;
    cin >> s1;
    int n=s.size();
    bool b = 1;
    for(int i=0; i<n; i++){
        char ch=s[i];
        c[ch-'a']++;
    }
    for(int i=0; i<n; i++){
        char ch=s1[i];
        if(ch=='*')continue;
        if(c[ch-'a']>0){
            c[ch-'a']--;
        }
        else{
            cout << 'N' << endl;
            b=0;
            break;
        }
    }
    if(b){
        cout << 'A' << endl;
    }
    return 0;
}
