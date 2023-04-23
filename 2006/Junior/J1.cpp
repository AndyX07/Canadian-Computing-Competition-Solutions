#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a>> b >> c >> d;
    int total = 0;
    if(a == 1){
        total += 461;
    }
    else if(a == 2){
        total += 431;
    }
    else if(a == 3){
        total += 420;
    }
    if(c == 1){
        total += 130;
    }
    else if(c == 2){
        total += 160;
    }
    else if(c == 3){
        total += 118;
    }
    if(b == 1){
        total += 100;
    }
    else if(b == 2){
        total += 57;
    }
    else if(b == 3){
        total += 70;
    }
    if(d == 1){
        total += 167;
    }
    else if(d == 2){
        total += 266;
    }
    else if(d == 3){
        total += 75;
    }
    cout << "Your total Calorie count is " << total << "." << endl;
    return 0;
}
