#include <bits/stdc++.h>

using namespace std;

int main()
{
    double w, h;
    cin >> w >> h;
    double BMI = w / pow(h, 2);
    if(BMI < 18.5){
        cout << "Underweight" << endl;
    }
    else if(BMI >= 18.5 && BMI <= 25){
        cout << "Normal weight" << endl;
    }
    else{
        cout << "Overweight" << endl;
    }
    return 0;
}
