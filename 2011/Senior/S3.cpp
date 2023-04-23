#include <bits/stdc++.h>

using namespace std;

int mag(int level, int x){
    int b=pow(5, level-1);
    if(level==0) return 0;
    if(x<b || x>=(b)*4){
        return 0;
    }
    else if(x>=b*2&&x<b*3){
        return b*2+mag(level-1, x%b);
    }
    else{
        return b+mag(level-1, x%b);
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i < t; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(c<mag(a, b)){
            cout << "crystal" << endl;
        }
        else{
            cout << "empty" << endl;
        }
    }
    return 0;
}
