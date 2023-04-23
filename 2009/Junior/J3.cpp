#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    int hh, mm;
    if(s1.size() == 4){
        hh = stoi(s1.substr(0, 2));
        mm = stoi(s1.substr(2));
    }
    else if(s1.size() == 3){
        hh = (s1[0] - '0');
        mm = stoi(s1.substr(1));
    }
    else{
        hh = 0;
        mm = stoi(s1);
    }
    int v, e, w, a, h, s;
    int b = stoi(s1);
    v = b-300;
    e = b-200;
    w = b-100;
    h = b+100;
    hh += 1;
    mm += 30;
    if(mm >= 60){
        mm %= 60;
        hh++;
    }
    if(hh > 24){
        hh-=24;
    }
    if(v < 0){
        v+=2400;
    }
    if(e < 0){
        e+=2400;
    }
    if(w < 0){
        w += 2400;
    }
    if(h > 2400){
        b-=2400;
    }
    cout << b <<" in Ottawa" << endl;
    cout << v <<" in Victoria" << endl;
    cout << e << " in Edmonton" << endl;
    cout << w << " in Winnipeg" << endl;
    cout << b << " in Toronto" << endl;
    cout << h << " in Halifax" << endl;
    if(hh != 0){
        cout << hh;
    }
    if(mm < 10){
        cout << "0" << mm;
    }
    else{
        cout << mm;
    }
    cout << " in St. John's" << endl;
    return 0;
}
