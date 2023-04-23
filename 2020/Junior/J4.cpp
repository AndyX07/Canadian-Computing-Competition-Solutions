#include <bits/stdc++.h>

using namespace std;

int main()
{
    string t, s;
    getline(cin, t);
    getline(cin, s);
    if(t.find(s) != string::npos){
        cout << "yes" << endl;
    }
    else{
        for(int i = 0; i < s.size(); i++){
            char c = s[0];
            s.erase(s.begin());
            s+=c;
            if(t.find(s) != string::npos){
                cout << "yes" << endl;
                return 0;
            }
        }
        cout << "no" << endl;
    }
    return 0;
}
