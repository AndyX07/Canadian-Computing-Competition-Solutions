#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s[6] = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};
    int v[6] = {7, 2, 3, 4, 4, 5};
    int a = 12;
    int b = 13;
    int w;
    cin >> w;
    int t1, t2
    if(w % 2 == 1){
        t2 = w/2;
        t1 = w-t2;
        int arr[4];
        memset(arr, 0, sizeof(arr));
        arr[1] = t1/2;
        arr[0] = t1-arr[1];
        arr[3] = t2/2;
        arr[2] = t2 - arr[3];
        for(int i = 0; i < 6; i++){
            cout << s[i];
            if(i > 1 && i < 5){
                for(int i = 0; i < arr[i-1]; i++){
                    cout << ".";
                }
            }
            if(i == 2){
                cout << endl;
            }
        }
        cout << endl;
    }
    else{

    }
    return 0;
}
