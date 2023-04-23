#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t;
    cin >> t;
    int n = 0, by = 0;
    int c1 = 0, c2 = 0;
    bool b1 = false, b2 = false;
    while(c1 < t){
        for(int i = 0; i < a; i++){
            n++;
            c1++;
            if(c1 == t){
                b1 = true;
                break;
            }
        }
        if(!b1){
            for(int i = 0; i < b; i++){
                c1++;
                n--;
                if(c1 == t){
                    b1 = true;
                    break;
                }
            }
        }
        if(b1){
            break;
        }
    }
    while(c2 < t){
        for(int i = 0; i < c; i++){
            by++;
            c2++;
            if(c2 == t){
                b2 = true;
                break;
            }
        }
        if(!b2){
            for(int i = 0; i < d; i++){
                c2++;
                by--;
                if(c2 == t){
                    b2 = true;
                    break;
                }
            }
        }
        if(b2){
            break;
        }
    }
    //cout << n << " " << by << endl;
    if(n == by){
        cout << "Tied" << endl;
    }
    else{
        cout << ((n > by)? "Nikky" : "Byron") << endl;
    }
    return 0;
}
