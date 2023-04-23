#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "ABCDE";
    int b, n;
    string str;
    while(cin >> b && cin >> n){
        if(b == 1){
            n %= 5;
            if(n != 0){
                str = s.substr(0, n);
                s.erase(0, n);
                s+=str;
            }
        }
        else if(b == 2){
            for(int i = 0; i < n; i++){
                char c = s[4];
                s.erase(4);
                str = "";
                str += c + s;
                s = str;
            }
        }
        else if(b == 3){
            n %= 2;
            for(int i = 0; i < n; i++){
                swap(s[0], s[1]);
            }
        }
        else{
            for(char ch : s){
                cout << ch << " ";
            }
            cout << endl;
        }
        if(b == 4 && n == 1){
            break;
        }
    }
    return 0;
}
