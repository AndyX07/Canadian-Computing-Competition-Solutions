#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    float x = 0, y = 0;
    if(a <= 250 && a > 100){
        x += (a-100)*0.25;
    }
    else if(a > 250){
        x += (a-100) * 0.25;
        y += (a-250) * 0.45;
    }
    x += b*0.15;
    y += b*0.35;
    x += c*0.2;
    y += c*0.25;
    cout << "Plan A costs " << x << endl;
    cout << "Plan B costs " << y << endl;
    if(x == y){
        cout << "Plan A and B are the same price." << endl;
    }
    else if(x > y){
        cout << "Plan B is cheapest." << endl;
    }
    else{
        cout << "Plan A is cheapest." << endl;
    }
    return 0;
}
