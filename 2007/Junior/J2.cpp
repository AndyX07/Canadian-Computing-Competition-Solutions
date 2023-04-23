#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, string> mp;
    mp.insert(pair<string, string>("CU", "see you"));
    mp.insert(pair<string, string>(":-)", "I'm happy"));
    mp.insert(pair<string, string>(":-(", "I'm unhappy"));
    mp.insert(pair<string, string>(";-)", "wink"));
    mp.insert(pair<string, string>(":-P", "stick out tongue"));
    mp.insert(pair<string, string>("(~.~)", "sleepy"));
    mp.insert(pair<string, string>("TA", "totally awesome"));
    mp.insert(pair<string, string>("CCC", "Canadian Computing Competition"));
    mp.insert(pair<string, string>("CUZ", "because"));
    mp.insert(pair<string, string>("TY", "thank-you"));
    mp.insert(pair<string, string>("YW", "you're welcome"));
    mp.insert(pair<string, string>("TTYL", "talk to you later"));
    string s;
    while(cin >> s){
        if(mp.find(s) == mp.end()){
            cout << s << endl;
        }
        else{
            cout << mp[s] << endl;
        }
    }
    return 0;
}
