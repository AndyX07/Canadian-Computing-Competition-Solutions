#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            int counter = 1;
            if(i < s.size()-1){
                while(s[i] == s[i+1]){
                    counter++;
                    i++;
                }
            }
            cout << counter << " " << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
