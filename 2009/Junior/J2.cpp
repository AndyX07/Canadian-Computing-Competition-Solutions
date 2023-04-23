#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int counter = 0;
    for(int i = 0; i <= d/a; i++){
        for(int j = 0; j <= d/b; j++){
            for(int k =0 ; k <= d/c; k++){
                if(i == 0 && j == 0 && k == 0){
                    continue;
                }
                else{
                    if(i*a + j*b + k*c <= d){
                        counter++;
                        cout << i <<" Brown Trout, "<<j<<" Northern Pike, "<<k<<" Yellow Pickerel" << endl;
                    }
                }
            }
        }
    }
    cout << "Number of ways to catch fish: " << counter << endl;
    return 0;
}
