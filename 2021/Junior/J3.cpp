#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    string current;
    while(cin >> s && strcmp(s.c_str(), "99999") != 0){
        int t = (s[0] - '0') + s[1] - '0';
        string str = s.substr(2);
        if(t == 0){
            cout << current << " " << str << endl;
        }
        else if(t %2 == 0){
            current = "right";
            cout << "right " << str << endl;
        }
        else{
            current = "left";
            cout << "left" << " " << str << endl;
        }
    }
    return 0;
}
