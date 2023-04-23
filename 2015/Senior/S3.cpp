#include <bits/stdc++.h>

using namespace std;

int main()
{
    int g,p;
    cin >> g >> p;
    int t = 0;
    set<int> s;
    for(int i=1; i<=g; i++){
        s.insert(-i);
    }
    bool b=1;
    for(int i=0; i<p; i++){
        int j;
        cin >> j;
        j*=-1;
        auto it=s.lower_bound(j);
        if(it==s.end()){
            b=0;
        }
        else{
            if(b){
                s.erase(it);
                t++;
            }
        }
    }
    cout << t << endl;
    return 0;
}
