#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int t = min(a, b);
    int t1 = max(a, b);
    int counter = 0;
    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= t1; j++){
            if(i + j == 10){
                counter++;
            }
        }
    }
    if(counter == 1){
        cout << "There is " << counter <<" way to get the sum 10." << endl;
    }
    else{
        cout << "There are " << counter <<" ways to get the sum 10." << endl;
    }
    return 0;
}
