#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int t = 0;
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            if(i+j == a && i >= j){
                t++;
            }
        }
    }
    cout << t << endl;
    return 0;
}
