#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0;
    int counter = 0;
    while(t-v[i] >= 0){
        t-=v[i];
        counter++;
        i++;
    }
    cout << counter << endl;
    return 0;
}
