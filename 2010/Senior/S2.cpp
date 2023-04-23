#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    char c[k];
    string s[k];
    for(int i = 0; i < k; i++){
        cin >> c[i] >> s[i];
    }
    string b;
    cin >> b;
    string ans="";
    while(b.size()!=0){
        for(int i = 0; i < k; i++){
            if(b.rfind(s[i],0)==0){
                ans+=c[i];
                b=b.substr(s[i].size(), b.size()-s[i].size());
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
