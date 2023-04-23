#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    map<string, vector<string>> mpx;
    cin>>x;
    for(int i = 0; i < x; i++){
        string s1, s2;
        cin >> s1 >> s2;
        mpx[s1].push_back(s2);
    }
    int y;
    map<string, vector<string>> mpy;
    cin >> y;
    for(int i = 0; i < y; i++){
        string s1, s2;
        cin >> s1 >> s2;
        mpy[s1].push_back(s2);
    }
    int g;
    cin >> g;
    int t=0;
    for(int i = 0; i < g; i++){
        vector<string> v(3);
        for(int i = 0; i < 3; i++){
            cin >> v[i];
        }
        for(auto a:v){
            auto it1=mpx.find(a);
            auto it2=mpy.find(a);
            if(it1!=mpx.end()){
                for(auto b:mpx[a]){
                    if(find(v.begin(), v.end(), b)==v.end()){
                        t++;
                    }
                }
            }
            if(it2!=mpy.end()){
                for(auto b:mpy[a]){
                    if(find(v.begin(), v.end(), b)!=v.end()){
                        t++;
                    }
                }
            }
        }
    }
    cout << t << endl;
    return 0;
}
