#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p1[5][2];
    int p2[5][2];
    memset(p1, 0, sizeof(p1));
    memset(p2, 0, sizeof(p2));
    for(int i = 0; i < 5; i++){
        char c1, c2;
        cin >> c1 >> c2;
        if(isupper(c1))p1[i][0]++;
        else p1[i][1]++;
        if(isupper(c2))p1[i][0]++;
        else p1[i][1]++;
    }
    for(int i = 0; i < 5; i++){
        char c1, c2;
        cin >> c1 >> c2;
        if(isupper(c1))p2[i][0]++;
        else p2[i][1]++;
        if(isupper(c2))p2[i][0]++;
        else p2[i][1]++;
    }
    int t;
    cin >> t;
    while(t--){
        bool b=1;
        for(int i = 0; i < 5; i++){
            char c;
            cin >> c;
            if(isupper(c)){
                if(p1[i][0]>=1||p2[i][0]>=1){
                    continue;
                }
                else{
                    b=0;
                }
            }
            else{
                if(p1[i][1]>=1&&p2[i][1]>=1){
                    continue;
                }
                else{
                    b=0;
                }
            }
        }
        if(b){
            cout << "Possible baby." << endl;
        }
        else{
            cout << "Not their baby!" << endl;
        }
    }
    return 0;
}
