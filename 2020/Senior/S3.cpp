#include <bits/stdc++.h>

using namespace std;

bool same(int a1[26], int a2[26]){
    for(int i = 0; i < 26; i++){
        if(a1[i]!=a2[i]) return false;
    }
    return true;
}

int main()
{
    string n, h;
    cin >> n >> h;
    unordered_set<string> s;
    if(n.size()<=h.size()){
        int cn[26], ch[26];
        memset(cn, 0, sizeof(cn));
        memset(ch, 0, sizeof(ch));
        for(char c:n){
            cn[c-'a']++;
        }
        for(int i = 0; i < n.size(); i++){
            ch[h[i]-'a']++;
        }
        if(same(cn, ch)){
            s.insert(h.substr(0, n.size()));
        }
        for(int i = n.size(); i<h.size(); i++){
            ch[h[i]-'a']++;
            ch[h[i-n.size()]-'a']--;
            if(same(cn, ch)){
                s.insert(h.substr(i-n.size()+1, n.size()));
            }
        }
        cout << s.size()<< endl;
    }
    else{
        cout << "0" << endl;
    }
    return 0;
}
