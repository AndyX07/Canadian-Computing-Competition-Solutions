#include <bits/stdc++.h>

using namespace std;

bool distinct(int a){
    string s = to_string(a);
    for(char c : s){
        if(count(s.begin(), s.end(), c) > 1){
            return false;
        }
    }
    return true;
}

int main()
{
    int a;
    cin >> a;
    a++;
    while(!distinct(a)){
        a++;
    }
    cout << a << endl;
    return 0;
}
