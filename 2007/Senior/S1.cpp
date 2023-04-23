#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){
        int y, m, d;
        cin >> y >> m >> d;
        y=2007-y;
        m-=2;
        d-=27;
        if(y>18){
            cout << "Yes" << endl;
        }
        else{
            if(y==18&&m<0){
                cout << "Yes" << endl;
            }
            else{
                if(y==18&&m==0&&d<=0){
                    cout << "Yes" << endl;
                }
                else{
                    cout <<"No" << endl;
                }
            }
        }
    }
    return 0;
}
