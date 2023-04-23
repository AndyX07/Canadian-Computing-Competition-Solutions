#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter the speed limit: ";
    int t;
    cin >> t;
    cout << "Enter the recorded speed of the car:";
    int t1;
    cin >> t1;
    int s = t1 - t;
    if(s <= 0){
        cout << "Congratulations, you are within the speed limit!" << endl;
    }
    else if(s >= 1 && s <= 20){
        cout << "You are speeding and your fine is $100." << endl;
    }
    else if(s > 20 && s <= 30){
        cout << "You are speeding and your fine is $270." << endl;
    }
    else{
        cout << "You are speeding and your fine is $500." << endl;
    }
    return 0;
}
