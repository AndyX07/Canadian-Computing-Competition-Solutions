#include <bits/stdc++.h>

using namespace std;

bool rsa(int a){
    int counter = 0;
    for(int i = 2; i < a; i++){
        if(a % i == 0){
            counter++;
        }
        if(counter > 2){
            return false;
        }
    }
    if(counter < 2){
        return false;
    }
    else{
        return true;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    int counter = 0;
    for(int i = a; i <= b; i++){
        if(rsa(i)){
            counter++;
        }
    }
    cout << "The number of RSA numbers between " << a << " and "<<b<<" is " << counter << endl;
    return 0;
}
