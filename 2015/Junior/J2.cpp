#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int h = 0;
    int sad = 0;
    if(s.size() >= 3){
        for(int i = 0; i < s.size()-3; i++){
            if(s.substr(i, 3) == ":-)") h++;
            else if(s.substr(i, 3) == ":-(") sad++;
        }
    }
    if(h == 0 && sad == 0){
        cout << "none" << endl;
    }
    else if(h == sad){
        cout << "unsure" << endl;
    }
    else{
        cout << ((h > sad)? "happy" : "sad") << endl;
    }
    return 0;
}
