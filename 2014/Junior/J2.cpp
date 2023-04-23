#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 0, b = 0;
    int v;
    cin >> v;
    for(int i = 0; i < v; i++){
        char c;
        cin >> c;
        if(c == 'A'){
            a++;
        }
        else{
            b++;
        }
    }
    if(a == b){
        cout << "Tie" << endl;
    }
    else{
        cout << ((a > b)? "A" : "B") << endl;
    }
    return 0;
}
