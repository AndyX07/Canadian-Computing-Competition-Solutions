#include <bits/stdc++.h>

using namespace std;

int main()
{
    int hh = 12;
    int mm = 0;
    int t;
    cin >> t;
    int counter = floor(t/720)*31;
    t%=720;
    for(int i = 0; i < t; i++){
        mm++;
        //cout << hh << " " << mm << endl;
        if(mm>59){
            mm%=60;
            hh++;
        }
        if(hh > 12){
            hh%=13;
            hh++;
        }
        if(mm >=10){
            if(hh < 10){
                string s = to_string(mm);
                if((s[0]-'0') - hh == s[1] - s[0]){
                    counter++;
                    //cout << counter << endl;
                }
            }
            else{
                string s = to_string(hh);
                string s1 = to_string(mm);
                if(s[1]-s[0] == s1[0]-s[1] && s1[0]-s[1] == s1[1]-s1[0]){
                    counter++;
                    //cout << counter << endl;
                }
            }
        }
    }
    cout << counter << endl;
    return 0;
}
