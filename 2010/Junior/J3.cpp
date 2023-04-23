#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 0, b = 0;
    int t;
    char x, y;
    while(cin >> t && t != 7){
        if(t == 1){
            cin >> x;
            int temp;
            cin >> temp;
            if(x == 'A'){
                a = temp;
            }
            else{
                b = temp;
            }
        }
        else if(t == 2){
            cin >> x;
            if(x == 'A'){
                cout << a << endl;
            }
            else{
                cout << b << endl;
            }
        }
        else if(t == 3){
            cin >> x >> y;
            if(x == 'A'){
                if(y == 'B'){
                    a+=b;
                }
                else{
                    a+=a;
                }
            }
            else{
                if(y == 'B'){
                    b+=b;
                }
                else{
                    b+=a;
                }
            }
        }
        else if(t == 4){
            cin >> x >> y;
            if(x == 'A'){
                if(y == 'B'){
                    a*=b;
                }
                else{
                    a*=a;
                }
            }
            else{
                if(y == 'B'){
                    b*=b;
                }
                else{
                    b*=a;
                }
            }
        }
        else if(t == 5){
            cin >> x >> y;
            if(x == 'A'){
                if(y == 'B'){
                    a-=b;
                }
                else{
                    a-=a;
                }
            }
            else{
                if(y == 'B'){
                    b-=b;
                }
                else{
                    b-=a;
                }
            }
        }
        else if(t == 6){
            cin >> x >> y;
            if(x == 'A'){
                if(y == 'B'){
                    a/=b;
                }
                else{
                    a/=a;
                }
            }
            else{
                if(y == 'B'){
                    b/=b;
                }
                else{
                    b/=a;
                }
            }
        }
    }
    return 0;
}
