#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    while(cin >> a && a != 0){
        int arr[a];
        vector<int> v;
        for(int i = 0; i < a; i++){
            cin >> arr[i];
        }
        if(a == 1){
            cout << "0" << endl;
        }
        else{
            for(int i = 0; i < a-1; i++){
                v.push_back(arr[i+1]-arr[i]);
            }
            int counter = 0;
            int t = v[counter];
            for(int i = 1; i <= a; i++){
                bool b = false;
                for(int j = i; j < a-1; j++){
                    if(v[j] != t){
                        b = true;
                        break;
                    }
                    counter++;
                    counter%=i;
                    t = v[counter];
                }
                if(!b){
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
