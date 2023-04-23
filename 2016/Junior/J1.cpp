#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    for(int i = 0; i < 6; i++){
        char c;
        cin >> c;
        if(c=='W'){
            t++;
        }
    }
    if(t == 5 || t == 6){
        cout << "1" << endl;
    }
    else if(t == 4 || t == 3){
        cout << "2" << endl;
    }
    else if(t == 1 || t == 2){
        cout << "3" << endl;
    }
    else{
        cout << "-1" << endl;
    }
    return 0;
}
