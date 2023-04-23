#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, s = 0;
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin, str);
        for(char c : str){
            if(c == 't' || c == 'T'){
                t++;
            }
            else if(c == 's' || c == 'S'){
                s++;
            }
        }
    }
    if(t > s){
        cout << "English" << endl;
    }
    else if(t < s){
        cout << "French" << endl;
    }
    else{
         cout << "French" << endl;
    }
    return 0;
}
