#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int k;
    cin >> k;
    cin.ignore();
    string s;
    getline(cin, s);
    string n = "";
    for(int i = 0; i < s.size(); i++){
        int v = 3*(i+1) + k;
        int it = a.find(s[i]);
        it-=v;
        if(it < 0){
            it+=26;
        }
        n+=a[it];
    }
    cout << n << endl;
    return 0;
}
